workspace "VoxelGame"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines "PLATFORM_WINDOWS"


	filter "configurations:Debug"
		defines "CFG_DEBUG"
		symbols "On"

	
	filter "configurations:Release"
		defines "CFG_RELEASE"
		optimize "On"

	
	filter "configurations:Dist"
		defines "CFG_DIST"
		optimize "On"