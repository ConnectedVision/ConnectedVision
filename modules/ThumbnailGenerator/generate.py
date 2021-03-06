import os
import platform
import subprocess

generatorFile = ""

if "ConnectedVision" in os.environ:
	generatorFile = os.path.normpath(os.path.join(os.environ["ConnectedVision"], "tools", "CodeFromTemplate", "bin", "ModuleGenerator.py"))
	
if not generatorFile or not os.path.exists(generatorFile):
	scriptFile = "activate." + ("bat" if platform.system() == "Windows" else "sh")
	
	raise Exception("\n\nFailed to locate the Connected Vision Module Code Generator.\nPlease execute the Connected Vision environment activation script" + (" by calling \"source ./" + scriptFile + "\"" if platform.system() == "Linux" else "") + ".\nThe " + scriptFile + " file is generated by Conan when calling the following command:\nconan install ConnectedVision/x.y.z@covi/stable -b outdated -g virtualenv")

subprocess.call(["python", generatorFile, "-m", os.path.dirname(os.path.realpath(__file__))])