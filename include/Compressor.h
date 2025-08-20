#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <vector>
#include <string>

class Compressor {
public: 
    virtual ~Compressor() = default;

    // Pure virtual methods (must be implemented by derived classes)
    virtual std::vector<char> compress(const std::vector<char>& data) = 0;
    virtual std::vector<char> decompress(const std::vector<char>& data) = 0;

    // Optional: return the algorithm name (useful for metadata)
    virtual std::string getName() const = 0;
};