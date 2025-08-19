#include "FileManager.h"

FileManager::FileManager(const std::string &filename) {
    setFile(filename);
}

bool FileManager::setFile(const std::string &filename) {
    std::filesystem::path potentialPath(filename);
    if(potentialPath.is_relative()) { // checks whether file is relative
        // Relative path: A relative path requires a starting location (e.g., the current working directory) to be resolved to an unambiguous file system location
        potentialPath = std::filesystem::current_path() / potentialPath;
    }
    if (std::filesystem::exists(potentialPath) && std::filesystem::is_regular_file(potentialPath)) { // if filePath is valid then set file size (priv var) and return true
        filePath = potentialPath;
        fileSize = std::filesystem::file_size(filePath); // file_size returns the size of file 
        return true;
    }

    filePath.clear();
    fileSize=0;
    return false;
}

bool FileManager::fileExists() const{
    return !filePath.empty() && std::filesystem::exists(filePath); // checks if private value for filePath exists
}

std::uintmax_t FileManager::getFileSize() const {
    return fileSize;
}
// return the file name of the current path value
std::string FileManager::getFileName() const {
    return filePath.filename().string();
}
// the parent_path() function is built into the file system library. It returns the parents direcotry
std::string FileManager::getFileExtension() const {
    return filePath.extension().string(); 
}

std::vector<char> FileManager::readChunk(std::size_t offset, std::size_t size) const {
    std::vector<char> buffer; 
    /*buffer is used as middleware between the processing of data and incoming because we need a 
    processor for the processing of data but sometimes processor is busy with some other task so 
    we need to transfer the data somewhere. need to be stored. */

    if(!fileExists()) {
        return buffer; // empty if file does not exists
    }

    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        return buffer; // if file cant be opened then it is empty
    }

    /*repositions the read pointer to the end of the file, often as 
    part of a process to determine the file's size or prepare for 
    specific file operations*/
    file.seekg(0, std::ios::end); // navigating to the end of the file (withouut reading the content), to determine the size of the file
    std::size_t fileLength = static_cast<size_t>(file.tellg());
    
    // Adjust size if reading beyond end of file
    if (offset >= fileLength) {
        return buffer; // indicates that the file has nothing else left to be read.
    }

    if (offset + size > fileLength) {
        size = fileLength - offset; // if we are trying to read beyond the file size, then we change it 
        // to read only the left last part of the file size (to fit the offset)
    }

    buffer.resize(size); // making sure buffer can hold the size parameters/indicated
    file.seekg(offset, std::ios::beg); // makes it so the file starts reading where the offset is set
    file.read(buffer.data(),size); // this reads the file contents, how much? - the size parameter limits how much is read
    // the file contents read is put in the buffer data
    return buffer; 
}

bool FileManager::writeFile(const std::string &outputPath, const std::vector<char> &data) const{
    std::ofstream out(outputPath, std::ios::binary);
    if (!out) {
        return false;
    }
    out.write(data.data(), static_cast<std::streamsize>(data.size()));
    return true;
}

static std::vector<std::filesystem::path> listFilesInDirectory(const std::string &dirPath) {
    std::vector<std::filesystem::path> files;
    std::filesystem::path directory(dirPath);

    if (std::filesystem::exists(directory) && std::filesystem::is_directory(directory)) {
        for (const auto &entry : std::filesystem::directory_iterator(directory)) {
            if (std::filesystem::is_regular_file(directory)) {
                files.push_back(entry.path());
            }
        }
    }
}