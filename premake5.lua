workspace "BigChunk"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
--IncludeDir = {}
--IncludeDir["GLFW"] = "BigChunk/vendor/GLFW/include"

--include "BigChunk/vendor/GLFW"
 
project "BigChunk"
	location "BigChunk"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "BigChunkpch.h"
	pchsource "BigChunk/src/BigChunkpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		--"%{IncludeDir.GLFW}"
	}

	links{
		--"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines{
		"BC_PLATFORM_WINDOWS",
		"BC_BUILD_DLL"
	}

	postbuildcommands{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "BC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BC_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs{
		"BigChunk/vendor/spdlog/include",
		"BigChunk/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines{
		"BC_PLATFORM_WINDOWS",
	}

	links{
		"BigChunk"
	}

	filter "configurations:Debug"
		defines "BC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BC_DIST"
		optimize "On"