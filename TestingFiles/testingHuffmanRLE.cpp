#include "HuffmanCompressor.h";
#include "FileManager.h";
#include <iostream>

int main() {
    FileManager fm("example.txt");
    if (!fm.fileExists()) { 
        std::cout << "File Not Found! \n" << std::endl;
        return 1;
    }

    // read entire file
    auto chunk = fm.readChunk(0,fm.getFileSize());

    HuffmanCompressor compressor;
    // compress the file
    auto compressed = compressor.compress(chunk);
    fm.writeFile("example.rle", compressed);

    // decompress the compressed file (data)
    auto decompressed = compressor.decompress(compressed);
    fm.writeFile("example_out", decompressed);

    std::cout << "Algorithm used: " << compressor.getName() << std::endl;
    std::cout << "Original size: " << chunk.size() << std::endl;
    std::cout << "Compressed size: " << compressed.size() << std::endl;

    return 0;
}