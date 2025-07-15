#include "../include/file_io.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib> // ensure compatibility with older compilers

int main() {
    std::filesystem::path currentDirectory = std::filesystem::current_path();
    std::string currentDirPathString = currentDirectory.string();
    std::cout << currentDirPathString << std::endl;
    std::cout << "Please input the name of the file you want to compress:" << std::endl;
    std::string filename;
    std::cin >> filename;
    std::string userDir = currentDirPathString + '/' + filename;
    if (fileExists(userDir)) {
        try {
            std::ifstream currFile = openFile(filename);
            std::cout << "File Exist: True" << std::endl;
            std::cout << "File Size: " << getFileSize(currFile) << std::endl; 
        } catch (const std::system_error& e) {
            std::cout << "Error on retrieving file information." << e.what() << std::endl;
        }
    } else {
        std::cout << "File does not exist" << std::endl;
    }
    return 0; 
}
