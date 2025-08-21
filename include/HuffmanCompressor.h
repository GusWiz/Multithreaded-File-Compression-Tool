#ifndef HUFFMANCOMPRESSOR_H
#define HUFFMANCOMPRESSOR_H

#include "Compressor.h"

class HuffmanCompressor : public Compressor { 
public:
    // both take in data (char) that will be either compressed or decompressed (using the Huffman Compressor)
    std::vector<char> compress(const std::vector<char>& data) override;
    std::vector<char> decompress(const std::vector<char>& data) override;

    std::string getName() const override {return "Huffman"; } // return the name of the algorithm
};

#endif