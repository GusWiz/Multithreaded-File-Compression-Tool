#pragma once

#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <filesystem>
#include <optional>
#include <cstddef>

// Using namespace for safety, platform compatibility, and convenience
namespace file_io {
    
    struct Chunk { 
        std::streampos start; // keeps track of the position within a stream
        std::streamsize size; // tracks the number of characters that have been read, written, or other input/output processes
    };


// open file to for reading contents
std::ifstream openInputFile(const std::string& filepath);

// close File object
void closeFile(std::ifstream& file);

// returns the size of the reading file
std::streamsize getFileSize(std::ifstream& file);

// Checks if the given directory exist in the system
bool fileExists(const std::string& filename);

// Converts string to Path (might not be needed)
std::filesystem::path stringToPath(const std::string& filepath);

// open a ofstream oject for writing purposes
std::ofstream openOutputFile(const std::string& filepath);

//Notes: 
// create a function that stops multi-threading issues, like
// race condition
// Approach to this function will be chunking the given file
// Allowing us to track have our threads deal with its own given chunks
// while keeping progress (estimate progress (percentage), track completeness)

}