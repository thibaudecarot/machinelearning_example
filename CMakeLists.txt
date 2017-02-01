cmake_minimum_required(VERSION 3.6)

project(DataMiningExample)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

message("Processing ${PROJECT_NAME}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Link source files
file(
        GLOB_RECURSE
        source_files
        src/source/*
        src/include/*
)

# Link include files
include_directories("src/include")

# Executable declaration
add_executable(${PROJECT_NAME} ${source_files})