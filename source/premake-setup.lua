
function SetupSolution()
	solution "hrengin"
		configurations { "Debug", "Release" }
		platforms { "x32", "x64" }
end

function SetupProject(prjname, ...)
	project(prjname)
		kind "SharedLib"
		language "C++"
		
		files { ... }
		files { "../../include/**" }
		libdirs { "../../lib", "../../dependencies/libs" }
		targetdir "../../lib"

		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols" }

		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize" }

		configuration "vs*"
			defines { "_CRT_SECURE_NO_WARNINGS" }
			vpaths { ["Includes"] = "../../include/**" }
			vpaths { ["Sources"] = "*.cpp" }
			vpaths { ["Headers"] = "*.h" }
			
	print(prjname);
end

function SetupDefines(prjname, conf, ...)
	project(prjname)
		configuration(conf)
			defines { ... }
end