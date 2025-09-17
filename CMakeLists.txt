cmake_minimum_required(VERSION 3.21.0)

# Only set the cxx_standard if it is not set by someone else
if(NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

# Generate compile_commands.json to make it easier to work with clang based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project("cpp-utility-types"
  LANGUAGES C CXX)

add_library(cpu-utility-types INTERFACE)

target_include_directories(cpu-utility-types INTERFACE include)
add_library(cut::types ALIAS cpu-utility-types)

option(ENABLE_TESTING "Enable tests" OFF)

if(${ENABLE_TESTING})
  enable_testing()
  add_subdirectory("test")
endif()