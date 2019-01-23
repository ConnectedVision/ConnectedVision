import os
import re
import shutil
from conans import CMake, ConanFile, tools



class ConnectedVision(ConanFile):
	name = "ConnectedVision"
	version = "2.4.0"
	license = "MIT"
	url = "https://github.com/ConnectedVision"
	settings = {"os": ["Windows", "Linux"], "compiler": ["Visual Studio", "gcc"], "arch": ["x86", "x86_64", "armv7hf"], "build_type": ["Debug", "Release"]}
	generators = "cmake"
	options = { "toolchain": "ANY" }
	default_options = "toolchain=None"
	requires = (("Boost/1.68.0@covi/2.4.0"),
		("FFmpeg/4.1@covi/2.4.0"),
		("Node.js/7.9.0@covi/2.3.0"),
		("OpenCV/3.4.3@covi/2.4.0"),
		("POCO/1.9.0@covi/2.4.0"),
		("RapidJSON/1.0.2@covi/2.3.0"),
		("SQLite/3.15.1@covi/2.3.0"))



	def requirements(self):
		if self.settings.compiler == "Visual Studio":
			self.requires("StackWalker/2014.12.28@covi/2.3.0")



	def source(self):
		self.output.info("")
		self.output.info("---------- source ----------")
		self.output.info("")
		
		self.run("git clone https://github.com/ConnectedVision/connectedvision.git " + self.name)

		with tools.chdir(self.name):
			self.run("git checkout " + self.version)



	def build(self):
		self.output.info("")
		self.output.info("---------- build ----------")
		self.output.info("")
		self.output.info("os        : " + str(self.settings.os))
		self.output.info("arch      : " + str(self.settings.arch))
		self.output.info("compiler  : " + str(self.settings.compiler) + " " + str(self.settings.compiler.version))
		self.output.info("build type: " + str(self.settings.build_type))

		if self.settings.compiler == "Visual Studio":
			self.output.info("runtime   : " + str(self.settings.compiler.runtime))
		else:
			self.output.info("libcxx    : " + str(self.settings.compiler.libcxx))
		
		if self.settings.compiler == "Visual Studio" and not self.settings.compiler.runtime in ["MDd", "MD"]:
			raise Exception("only the dynamic runtime MD(d) is supported")
		
		installDir = os.path.abspath(os.path.join(os.getcwd(), "install"))
		
		sourceDir = os.path.join(os.getcwd(), self.name, "build_env", "cmake")
		buildDir = os.path.join(os.getcwd(), "build", "core")
		
		if not os.path.exists(buildDir):
			os.makedirs(buildDir)
		
		cmake = CMake(self)
		
		# # using the Conan CMake helper functions (cmake.configure and cmake.build) does not seem to work for this project with Conan 0.25.1 ("CMake Error at conan.cmake:283 (message): conanbuildinfo.cmake doesn't exist in [...]")
		# # instead, use the command line string and remove the DCONAN_EXPORTED flag which causes the problem (setting it to zero is also possible)
		# opts = dict()
		# opts["CMAKE_INSTALL_PREFIX"] = installDir
		# cmake.configure(source_dir=sourceDir, build_dir=buildDir, defs=opts)
		# cmake.build(target="install")
		
		cmakeStr = re.sub(" *-DCONAN_EXPORTED=\"1\" *", " ", cmake.command_line)
		
		if self.options.toolchain:
			toolchain = str(self.options.toolchain)
			
			if not os.path.exists(toolchain) or not os.path.isfile(toolchain):
				raise Exception("the specified toolchain is not a valid file: " + toolchain)
			
			cmakeStr += " -DCMAKE_TOOLCHAIN_FILE=" + toolchain
		
		cmd = "cd " + buildDir
		cmd += " && cmake " + cmakeStr + " -DCMAKE_INSTALL_PREFIX=" + installDir + " " + sourceDir
		cmd += " && cmake --build . --target install --config " + str(self.settings.build_type)
		
		# speed up the build when using GCC by parallelizing compilation with the -j parameter (for Visual Studio the /MP flag is used in CMAKE_CXX_FLAGS of CMakeLists.txt)
		if self.settings.compiler == "gcc":
			cmd += " -- -j" + str(tools.cpu_count())
		
		self.run(cmd)



	def package(self):
		self.output.info("")
		self.output.info("---------- package ----------")
		self.output.info("")
		
		installDir = os.path.join(os.getcwd(), "install")
		
		self.copy("*", src=os.path.join(installDir, "include"), dst="include")
		self.copy("common.cmake", src=os.path.join(self.build_folder, self.name, "build_env", "cmake"), dst="include")
		self.copy("*", src=os.path.join(installDir, "lib"), dst="lib")
		
		# copy the Module Generator including the required schemata
		self.copy("*", src=os.path.join(self.build_folder, self.name, "tools", "CodeFromTemplate"), dst=os.path.join("bin", "tools", "CodeFromTemplate"))
		shutil.rmtree(os.path.join(self.package_folder, "bin", "tools", "CodeFromTemplate", "test"))
		self.copy("*", src=os.path.join(self.build_folder, self.name, "core", "def"), dst=os.path.join("bin", "core", "def"))



	def package_info(self):
		self.output.info("")
		self.output.info("---------- package_info ----------")
		self.output.info("")
		
		libs = list()
		
		# check which libraries were compiled and add the to the list of libs
		for f in os.listdir(os.path.join(self.package_folder, "lib")):
			lib = os.path.splitext(f)[0]
			
			if self.settings.os == "Linux":
				lib = re.sub("^lib", "", lib)
			
			libs.append(lib)
		
		# move the core lib to end end of the list for Linux builds as the build order is crucial
		if self.settings.os == "Linux" and "ConnectedVisionCore" in libs:
			libs.remove("ConnectedVisionCore")
			libs.append("ConnectedVisionCore")
			
		self.cpp_info.libs = libs
		
		self.env_info.ConnectedVision = os.path.join(self.package_folder, "bin")
