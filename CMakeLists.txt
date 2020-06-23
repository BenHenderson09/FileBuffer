project(FileBuffer)
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Setup source files
set(SOURCE_FILES 
    src/FileBuffer.cpp
    src/getFileSize/getFileSize.cpp)

# Setup header files
set(HEADER_FILES
    src/FileBuffer.hpp)

# Create the shared library
add_library(FileBuffer SHARED ${SOURCE_FILES})

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib)

# Install library headers
install(FILES ${HEADER_FILES} DESTINATION include/${PROJECT_NAME})