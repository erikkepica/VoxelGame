workspace "VoxelGame"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
resourceDir = "res"


include "VoxelGame/vendor/glfw/"
include "VoxelGame/vendor/glad/"

project "VoxelGame"
	location "VoxelGame"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/glfw/include",
		"%{prj.name}/vendor/glad/include"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}


-- Custom build step to copy the resources folder


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines "PLATFORM_WINDOWS"
		postbuildcommands {
			"{COPY} " .. resourceDir .. " ../bin/" .. outputdir .. "/%{prj.name}/res"
		}


	filter "configurations:Debug"
		defines "CFG_DEBUG"
		symbols "On"

	
	filter "configurations:Release"
		defines "CFG_RELEASE"
		optimize "On"
		postbuildcommands { "commands" }

	
	filter "configurations:Dist"
		defines "CFG_DIST"
		optimize "On"
