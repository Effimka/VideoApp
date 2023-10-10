set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
cmake_minimum_required(VERSION 3.20)

set(ProjectName VideoApp)
project(${ProjectName})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Release)

if (WIN32)
	set(FFMPEG_PATH_OS x64-windows)
endif(WIN32)

if (UNIX)
	set(FFMPEG_PATH_OS x64-linux) #I am not sure
endif(UNIX)

if (APPLE)
	set(FFMPEG_PATH_OS x64-osx)
endif(APPLE)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/vcpkg/installed/${FFMPEG_PATH_OS}/share/ffmpeg")
find_package(ffmpeg)

include_directories(${FFMPEG_INCLUDE_DIRS})
add_executable(${ProjectName} "Source/main.cpp")
target_link_libraries(${ProjectName} ${FFMPEG_LIBRARIES})