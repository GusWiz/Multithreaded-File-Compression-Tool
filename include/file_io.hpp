#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

std::ifstream openFile(const std::string& fileName);
std::ofstream closeFile(const std::ifstream& file);