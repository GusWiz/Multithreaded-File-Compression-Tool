#include "file_io.hpp"
#include <fstream> // librarry for Reading/writing files
#include <iterator> 
#include <algorithm>
#include <string>


/*
file_io.hpp
- Declares functions for reading from and writing to files in binary mode.
- Supports chunking files for parallel processing.
 */

std::ifstream openFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file.");
    }
    return file; // returns the file obj 
}

void closeFile(std::ifstream& file) {
    if (file.is_open()) {
        file.close();
    }
}

std::streamsize getFileSize(std::ifstream& file) {
    const auto currentPos = file.tellg();
    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(currentPos);
    return size;
}

bool fileExists(const std::string& filename) {
    return std::filesystem::exists(filename);
}

std::filesystem::path stringToPath(const std::string& filename) {
    std::filesystem::path filePath = filename;
    return filePath;
}
