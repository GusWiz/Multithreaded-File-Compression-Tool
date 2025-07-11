#ifndef file_io_hpp
#define file_io_hpp
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <filesystem>

std::ifstream openFile(const std::string& fileName);
void closeFile(const std::ifstream& file);
std::streamsize getFileSize(const std::ifstream& file);
bool fileExists(const std::string& filename);
// create a function that stops multi-threading issues, like
// race condition
// Approach to this function will be chunking the given file
// Allowing us to track have our threads deal with its own given chunks
// while keeping progress (estimate progress (percentage), track completeness)

#endif