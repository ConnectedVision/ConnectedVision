import os
import platform
import re

from conans import AutoToolsBuildEnvironment, ConanFile, tools
from conans.tools import download
from conans.tools import unzip, replace_in_file
from conans import CMake


class LibCurlConan(ConanFile):
	name = "libcurl"
	version = "7.47.1"
	license="MIT/X derivate license, https://curl.haxx.se/docs/copyright.html"
	url="https://curl.haxx.se"
	ZIP_FOLDER_NAME = "curl-%s" % version
	generators = "cmake", "txt"
	settings = "os", "arch", "compiler", "build_type"
	options = {"shared": [True, False], # SHARED IN LINUX IS HAVING PROBLEMS WITH LIBEFENCE
				"with_openssl": [True, False], 
				"disable_threads": [True, False],
				"with_ldap": [True, False], 
				"custom_cacert": [True, False],
				"darwin_ssl": [True, False],
				"with_libssh2": [True, False],
				"with_libidn": [True, False], 
				"with_librtmp": [True, False],
				"with_libmetalink": [True, False]}
	default_options = "shared=False", "with_openssl=False", "disable_threads=False", \
						"with_ldap=False", "custom_cacert=False", "darwin_ssl=True", \
						"with_libssh2=False", "with_libidn=False", "with_librtmp=False", \
						"with_libmetalink=False"
	exports = ["CMakeLists.txt", "FindCURL.cmake"]
	
	def config(self):
		del self.settings.compiler.libcxx
		
		if self.options.with_openssl:
			if self.settings.os != "Macos" or not self.options.darwin_ssl:
				self.requires.add("OpenSSL/1.0.2g@covi/2.4.0", private=False)
				self.options["OpenSSL"].shared = self.options.shared
			
		if self.settings.os != "Macos":
			try:
				self.options.remove("darwin_ssl")
			except:
				pass
		
		self.requires.add("zlib/1.2.11@covi/2.3.0", private=False)
	
	
	
	def source(self):
		zip_name = "curl-%s.tar.gz" % self.version
		download("https://curl.haxx.se/download/%s" % zip_name, zip_name, verify=False)
		unzip(zip_name)
		os.unlink(zip_name)
		download("https://curl.haxx.se/ca/cacert.pem", "cacert.pem", verify=False)
		if self.settings.os != "Windows":
			self.run("chmod +x ./%s/configure" % self.ZIP_FOLDER_NAME)
	
	
	
	def build(self):
		self.output.info("")
		self.output.info("---------- build ----------")
		self.output.info("")
		self.output.info("os        : " + str(self.settings.os))
		self.output.info("arch      : " + str(self.settings.arch))
		self.output.info("build_type: " + str(self.settings.build_type))
		
		if self.settings.compiler == "Visual Studio":
			self.output.info("runtime   : " + str(self.settings.compiler.runtime))
		
		if self.settings.os == "Linux" or self.settings.os == "Macos":
			suffix = " --without-libidn " if not self.options.with_libidn else "--with-libidn"
			suffix += " --without-libssh2 " if not self.options.with_libssh2 else "--with-libssh2"
			suffix += " --without-librtmp " if not self.options.with_librtmp else "--with-librtmp"
			suffix += " --without-libmetalink " if not self.options.with_libmetalink else "--with-libmetalink"
			
			if self.settings.compiler == "gcc" and self.settings.arch == "armv7hf" and not re.match("arm.*", platform.machine()):
				suffix += " --host=arm-linux-gnueabihf "
			
			if self.options.with_openssl:
				if self.settings.os == "Macos" and self.options.darwin_ssl:
					suffix += "--with-darwinssl "
				else:
					suffix += "--with-ssl "
			else:
				suffix += "--without-ssl "
			
			if not self.options.shared:
				suffix += " --disable-shared" 
			
			if self.options.disable_threads:
				suffix += " --disable-thread"
			
			if not self.options.with_ldap:
				suffix += " --disable-ldap"
			
			if self.options.custom_cacert:
				suffix += ' --with-ca-bundle=cacert.pem'
			
			env = AutoToolsBuildEnvironment(self)
			
			# Hack for configure, don't know why fails because it's not able to find libefence.so
			if "efence" in env.libs:
				env.libs.remove("efence")
			
			old_str = r"-install_name \$rpath/"
			new_str = "-install_name "
			replace_in_file("%s/configure" % self.ZIP_FOLDER_NAME, old_str, new_str)
			
			with tools.environment_append(env.vars):
				with tools.chdir(self.ZIP_FOLDER_NAME):
					configure = "./configure " + suffix
					self.output.warn(configure)
					self.run(configure)
					self.run("make -j" + str(tools.cpu_count()))
		else:
			# Do not compile curl tool, just library
			conan_magic_lines = '''project(CURL)
cmake_minimum_required(VERSION 3.0)
include(../conanbuildinfo.cmake)
CONAN_BASIC_SETUP()
'''
			replace_in_file("%s/CMakeLists.txt" % self.ZIP_FOLDER_NAME, "cmake_minimum_required(VERSION 2.8 FATAL_ERROR)", conan_magic_lines)
			replace_in_file("%s/CMakeLists.txt" % self.ZIP_FOLDER_NAME, "project( CURL C )", "")
			
			replace_in_file("%s/src/CMakeLists.txt" % self.ZIP_FOLDER_NAME, "add_executable(", "IF(0)\n add_executable(")
			replace_in_file("%s/src/CMakeLists.txt" % self.ZIP_FOLDER_NAME, "install(TARGETS ${EXE_NAME} DESTINATION bin)", "ENDIF()") # EOF
			
			cmake = CMake(self)
			
			opts = dict()
			opts["BUILD_SHARED_LIBS"] = self.options.shared
			opts["CURL_STATICLIB"] = not self.options.shared
			opts["CURL_DISABLE_LDAP"] = not self.options.with_ldap
			
			buildDir = os.path.join(self.ZIP_FOLDER_NAME, "_build")
			os.makedirs(buildDir)
			cmake.configure(defs=opts, source_dir=os.pardir, build_dir=buildDir)
			cmake.build()
	
	
	
	def package(self):
		""" Define your conan structure: headers, libs, bins and data. After building your
			project, this method is called to create a defined structure:
		"""
		
		# Copy findZLIB.cmake to package
		self.copy("FindCURL.cmake", ".", ".")
		
		# Copying zlib.h, zutil.h, zconf.h
		self.copy("*.h", "include/curl", "%s" % (self.ZIP_FOLDER_NAME), keep_path=False)
		
		# Copy the certs to be used by client
		self.copy(pattern="cacert.pem", keep_path=False)
		
		# Copying static and dynamic libs
		if self.settings.os == "Windows":
			if self.options.shared:
				self.copy(pattern="*.dll", dst="bin", src=self.ZIP_FOLDER_NAME, keep_path=False)
			self.copy(pattern="*.lib", dst="lib", src=self.ZIP_FOLDER_NAME, keep_path=False)
		else:
			if self.options.shared:
				if self.settings.os == "Macos":
					self.copy(pattern="*.dylib", dst="lib", keep_path=False)
				else:
					self.copy(pattern="*.so*", dst="lib", src=self.ZIP_FOLDER_NAME, keep_path=False)
			else:
				self.copy(pattern="*.a", dst="lib", src=self.ZIP_FOLDER_NAME, keep_path=False)
	
	
	
	def package_info(self):
		if self.settings.os != "Windows":
			self.cpp_info.libs = ['curl']
			if self.settings.os == "Linux":
				self.cpp_info.libs.extend(["rt"])
				if self.options.with_libssh2:
					self.cpp_info.libs.extend(["ssh2"]) 
				if self.options.with_libidn:
					self.cpp_info.libs.extend(["idn"]) 
				if self.options.with_librtmp:
					self.cpp_info.libs.extend(["rtmp"]) 
			if self.settings.os == "Macos":
				if self.options.with_ldap:
					self.cpp_info.libs.extend(["ldap"])
				if self.options.darwin_ssl:
					self.cpp_info.libs.extend(["/System/Library/Frameworks/Cocoa.framework", "/System/Library/Frameworks/Security.framework"])
					
		else:
			self.cpp_info.libs = ['libcurl_imp'] if self.options.shared else ['libcurl']
			self.cpp_info.libs.append('Ws2_32')
		
		if not self.options.shared:
			self.cpp_info.defines.append("CURL_STATICLIB=1")
