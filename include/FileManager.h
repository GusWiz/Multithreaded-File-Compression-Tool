#include <filesystem>
#include <vector>
class FileManager { 
private:
    std::filesystem::path filePath;
    std::uintmax_t fileSize; // this value is  unsigned long long
public:
    FileManager() = default; // makes default constructor (blank)
    FileManager(const std::string &filename); 
    // Concanates working directory + filename
    // checks if it exists
    // sotres filePath and fileSize
    bool setFile(const std::string &filename); // sets filePath and validates
    bool fileExists() const; // returns std::filesystem::exists(filePath) (getter func)
    std::uintmax_t getFileSize() const; // returns stored fileSize (getter)
    
    std::string getFileName() const; // just name without path
    std::string getFileExtension() const;
    
    /*
    Opens file in binary mode.
    Moves to offset (using seekg).
    Reads up to size bytes.
    */
    std::vector<char> readChunk(std::size_t offset, std::size_t size) const;
    // Writes vector of bytes to a new file.
    bool writeFile(const std::string &outputPath, const std::vector<char> &data) const;

    // Iterates over directory and returns a list of file paths.
    static std::vector<std::filesystem::path> listFilesInDirectory(const std::string &dirPath);
};