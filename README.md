# FileBuffer
FileBuffer is a class which is designed to take a file location as input, read the file contents,
write them into a dynamically allocated memory buffer (on the heap) and then expose some methods
to work with this buffer in a more intuitive manner.

## Program Details
 - Made with C++
 - Built with CMake
 - No third party libraries
 
 ## Usage
 Carry out the following instructions. Run as root.
 1. `git clone https://github.com/BenHenderson09/FileBuffer`
 2. `mkdir -p FileBuffer/build && cd FileBuffer/build`
 3. `cmake .. && make`
 
 This will leave you with an `include` and a `lib` directory inside the `build` directory.
 The `include` directory contains the header and the `lib` directory contains the library.
