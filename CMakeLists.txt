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

# CMake seems to have no way to enable/disable testing per subproject,
# so we provide an option similar to BUILD_TESTING, but just for LBM.
option(LBM_BUILD_TESTING "enable testing for mpm" ON)

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

# Include directories
include_directories(BEFORE
  ${lbm_SOURCE_DIR}/external/
  ${lbm_SOURCE_DIR}/include/
)

# Compile and link
SET(lbm_src
  ${lbm_SOURCE_DIR}/src/lattice.cc
)
add_executable(lbm ${lbm_SOURCE_DIR}/src/main.cc ${lbm_src})

# Unit test
if(LBM_BUILD_TESTING)
  SET(test_src
    ${lbm_SOURCE_DIR}/tests/lattice_test.cc
    ${lbm_SOURCE_DIR}/tests/test_main.cc
  )
  add_executable(lbmtest ${lbm_src} ${test_src})
  add_test(NAME lbmtest COMMAND $<TARGET_FILE:lbmtest>)
  enable_testing()
endif()

# Coverage
find_package(codecov)
if(ENABLE_COVERAGE)
  add_executable(lbmtest_coverage ${lbm_src} ${test_src})
  add_coverage(lbmtest_coverage)
endif()
