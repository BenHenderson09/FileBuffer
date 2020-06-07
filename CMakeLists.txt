project(FileBuffer)
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Setup source files
set(SOURCE_FILES 
    src/FileBuffer.cpp
    src/getFileSize/getFileSize.cpp)

# Create the static library
add_library(FileBuffer STATIC ${SOURCE_FILES})

# Pack the header and library into "lib" and "include" directories
add_custom_command(TARGET FileBuffer POST_BUILD COMMAND
    mkdir include lib &&
    cp ../src/FileBuffer.hpp include/FileBuffer.hpp &&
    mv libFileBuffer.a lib)