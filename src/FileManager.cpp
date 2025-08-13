#include "FileManager.h"

bool FileManager::setFile(const std::string &filename) {
    std::filesystem::path currentDir = std::filesystem::current_path(); // gets the current directory of the program
    filePath = currentDir.string() + '/' + filename; // concanates the curr directory + filename
    if (FileManager::fileExists() == 1) { // if filePath is valid then set file size (priv var) and return true
        fileSize = std::filesystem::file_size(filePath);
        return 1;
    }
    return 0;
}

bool FileManager::fileExists() const{
    return std::filesystem::exists(filePath); // check priv val for filePath exists
}

std::uintmax_t FileManager::getFileSize() const {
    return fileSize;
}

std::string FileManager::getFileName() const {
    return filePath.filename().string();
}
// both functions are alamost built into the file system library.
std::string FileManager::getFileExtension() const {
    return filePath.parent_path().string();
}

std::vector<char> FileManager::readChunk(std::size_t offset, std::size_t size) const {

}

bool FileManager::writeFile(const std::string &outputPath, const std::vector<char> &data) const{

}

static std::vector<std::filesystem::path> listFilesInDirectory(const std::string &dirPath) {
    
}