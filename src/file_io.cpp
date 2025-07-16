#include "file_io.hpp"
#include <fstream> // librarry for Reading/writing files
#include <iterator> 
#include <algorithm>
#include <string>

namespace file_io {
/*
file_io.hpp
- Declares functions for reading from and writing to files in binary mode.
- Supports chunking files for parallel processing.
 */

std::ifstream openInputFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for reading.");
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

std::filesystem::path stringToPath(const std::string& filepath) {
    std::filesystem::path path = filepath;
    return path;
}

std::ofstream openOutputFile(const std::string& filepath) {
    std::ofstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing.");
    }
    return file;
}

}