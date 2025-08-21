#include "HuffmanCompressor.h";
// defines integer types with specific widths. Which allows for precise control over int size
// Helpful for file compression
#include <cstdint> 

// Implementing a Run-Length Encoding for testing
std::vector<char> HuffmanCompressor::compress(const std::vector<char>& data) {
    std::vector<char> compressed;
    if (data.empty()) {
        return compressed;
    }

    char currentChar = data[0];
    uint8_t count = 1;
    
    for (size_t i = 1; i < data.size(); i++) {
        // the reason we are checking that it is less than 255 is due to 2^8 (aka the uint8_t)
        if (data[i] == currentChar && count < 255) {
            count++;
        } else {
            compressed.push_back(static_cast<char>(count));
            compressed.push_back(currentChar);
            currentChar = data[i];
            count = 1;
        }
    }

    // flush last run of the loop
    compressed.push_back(static_cast<char>(count));
    compressed.push_back(currentChar);
    
    return compressed;
}

std::vector<char> HuffmanCompressor::decompress(const std::vector<char>& data) {
    std::vector<char> decompressed;

    // the reason we have to use this type of loop would be to because our compressed data will be like "e5 v5..."
    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        uint8_t count = static_cast<uint8_t>(data[i]); // the first "i" is the count of the variable
        char value = data[i + 1]; // Grabbing the char "variable" that was compressed

        for (uint8_t j = 0; j < count; j++) {
            decompressed.push_back(value);
        }
    }

    return decompressed;
}
