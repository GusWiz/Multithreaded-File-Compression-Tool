#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

std::ifstream openFile(const std::string& fileName);
void closeFile(const std::ifstream& file);
std::streamsize getFileSize(const std::ifstream& file);

// create a function that stops multi-threading issues, like
// race condition
// Approach to this function will be chunking the given file
// Allowing us to track have our threads deal with its own given chunks
// while keeping progress (estimate progress (percentage), track completeness)