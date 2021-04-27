project(lbm LANGUAGES CUDA CXX)

enable_language(CUDA)
include(CheckLanguage)
check_language(CUDA)

set(CMAKE_CXX_STANDARD 14)

cmake_minimum_required(VERSION 3.12)

SET(CMAKE_COLOR_MAKEFILE ON)
SET(CMAKE_VERBOSE_MAKEFILE OFF)

# General compile settings
IF (NOT CMAKE_BUILD_TYPE)
 #SET(CMAKE_BUILD_TYPE "Debug")
 SET(CMAKE_BUILD_TYPE "Release")
ENDIF (NOT CMAKE_BUILD_TYPE)

# CMake Modules
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# CUDA PACKAGE
if(NOT DEFINED CMAKE_CUDA_STANDARD)
    set(CMAKE_CUDA_STANDARD 11)
    set(CMAKE_CUDA_STANDARD_REQUIRED ON)
endif()
set(CUDA_SEPARABLE_COMPILATION ON)
set(CUDA_PROPAGATE_HOST_FLAGS OFF)
set(CUDA_HOST_COMPILER g++)

# Include
include_directories(BEFORE
  ${lbm_SOURCE_DIR}/include/
)

# COMPILE AND LINK
add_executable(lbm
  ${lbm_SOURCE_DIR}/src/main.cc
)

# Coverage
#find_package(codecov)
#if(ENABLE_COVERAGE)
#  add_executable(lbmtest_coverage ${lbm_src} ${test_src})
#  add_coverage(lbmtest_coverage)
#endif()
