#include <string>
#include <fstream>
#include <stdexcept>
#include "FileBuffer.hpp"
#include "getFileSize/getFileSize.hpp"

FileBuffer::FileBuffer(const char* fileLocation){
    if (!fileLocation){
        throw std::runtime_error("File location must be provided.");
    }
    else {
        writeFileContentsToBuffer(std::string{fileLocation});
    }
}

FileBuffer::FileBuffer(const std::string& fileLocation){
    writeFileContentsToBuffer(fileLocation);
}

void FileBuffer::writeFileContentsToBuffer(const std::string& fileLocation){
    std::ifstream file(fileLocation);
    fileSizeInBytes = getFileSize(fileLocation);
    
    // Dynamically allocated buffer
    uint8_t* heapBasedBuffer{new uint8_t[fileSizeInBytes]};

    // Copy over each byte to the buffer
    for (int i{0}; i < fileSizeInBytes; i++){
        heapBasedBuffer[i] = file.get();
    }

    this->heapBasedBuffer = heapBasedBuffer;
}

FileBuffer::~FileBuffer(){
    // Free up memory
    delete[] heapBasedBuffer;
}

uint8_t FileBuffer::operator[](long byteIndex) const {
    return heapBasedBuffer[byteIndex];
}

long FileBuffer::getFileSizeInBytes() const {
    return fileSizeInBytes;
}

void FileBuffer::copyBufferContentsToAnotherBuffer(uint8_t*& otherBuffer, long sizeOfOtherBuffer) const {
    if (sizeOfOtherBuffer < fileSizeInBytes){
        throw std::runtime_error("Provided buffer is not large enough to hold the file contents.");
    }

    for (long byteIndex{0}; byteIndex < fileSizeInBytes; byteIndex++){
        otherBuffer[byteIndex] = heapBasedBuffer[byteIndex];
    }
}