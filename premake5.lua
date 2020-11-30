workspace "Starrlight"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Starrlight"
	location "Starrlight"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SL_PLATFORM_WINDOWS",
			"SL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SL_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Starrlight/vendor/spdlog/include",
		"Starrlight/src"
	}

	links
	{
		"Starrlight"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SL_DIST"
		optimize "On"