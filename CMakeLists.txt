
cmake_minimum_required(VERSION "4.0")
project(LIBRADIAL VERSION "1.0" LANGUAGES C)

option(USE_CXX "Build using the C++ Standard Library for linking into C++ projects (default: ON)." ON)

set(C_STD 17 CACHE STRING "Configure the C standard revision (default: 17)")
set(CXX_STD 17 CACHE STRING "Configure the C++ standard revision (default: 17)")

set(CMAKE_C_STANDARD ${C_STD})
set(CMAKE_CXX_STANDARD ${CXX_STD})

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
	set(LIBRADIAL_LINUX_BUILD ON)
	set (CMAKE_C_COMPILER "/usr/bin/gcc")
	set (CMAKE_CXX_COMPILER "/usr/bin/g++")
elseif (UNIX)
	set(LIBRADIAL_LINUX_BUILD OFF)
	set (CMAKE_C_COMPILER "/usr/bin/clang")
	set (CMAKE_CXX_COMPILER "/usr/bin/clang++")
else()
	set(LIBRADIAL_LINUX_BUILD OFF)
endif()

if (USE_CXX)
	set(CMAKE_C_COMPILER ${CMAKE_CXX_COMPILER})
endif()

file(GLOB_RECURSE LIBRADIAL_C_SRC "${PROJECT_SOURCE_DIR}/lib/src/c/*.c" "${PROJECT_SOURCE_DIR}/api/src/c/*.c")

add_library(libradial STATIC)
add_library(dlibradial SHARED "${PROJECT_SOURCE_DIR}/dummyfiles/dummy.c")
if (NO_CXX)
	target_sources(libradial PRIVATE ${LIBRADIAL_C_SRC})
	set_target_properties(libradial PROPERTIES
		LINKER_LANGUAGE C
		OUTPUT_NAME "radial.c"
	)
	set_target_properties(dlibradial PROPERTIES
		LINKER_LANGUAGE C
		OUTPUT_NAME "radial.c"
	)
else()
	enable_language(CXX)
	set(CMAKE_C_COMPILER ${CMAKE_CXX_COMPILER})
	set(CMAKE_CXX_COMPILE_FEATURES ON)
	set(CMAKE_CXX_EXTENSIONS ON)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
	target_sources(libradial PRIVATE ${LIBRADIAL_C_SRC} PRIVATE ${LIBRADIAL_CXX_SRC})
	set_target_properties(libradial PROPERTIES
		OUTPUT_NAME "radial"
	)
	set_target_properties(dlibradial PROPERTIES
		OUTPUT_NAME "radial"
	)
endif()

target_link_libraries(dlibradial libradial)

if (LIBRADIAL_LINUX_BUILD)
	find_library(LIBM_PATH m)
	if (NOT LIBM_PATH)
		message(FATAL_ERROR "Couldn't find dependency: libm.so (GNU C Standard Math Library).")
	endif()
	add_library(LIBM SHARED IMPORTED)
	set_target_properties(LIBM PROPERTIES IMPORTED_LOCATION ${LIBM_PATH})
	target_link_libraries(libradial LIBM)
	target_link_libraries(dlibradial LIBM)
endif()

include_directories("${PROJECT_SOURCE_DIR}/api/include")
