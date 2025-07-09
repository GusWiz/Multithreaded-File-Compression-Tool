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

std::ofstream closeFile(std::ifstream& file) {
    if (file.is_open()) {
        file.close();
    }
}

