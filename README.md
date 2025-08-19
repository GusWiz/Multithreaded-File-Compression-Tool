# Multithreaded-File-Compression-Tool
This tool allows you to compress a files

# Structure of the Program:

multithreaded-compressor/FileManager
 ├─ validateFile()
 ├─ getFileSize()
 ├─ readChunk(offset, size)

Compressor (abstract base class)
 ├─ compress(data) [pure virtual]
 ├─ decompress(data) [pure virtual]

HuffmanCompressor : public Compressor
 ├─ compress(data)
 ├─ decompress(data)

ThreadPool
 ├─ submitTask(function)
 ├─ joinAll()

CompressionJob
 ├─ filePath
 ├─ chunkSize
 ├─ compressor
 ├─ execute()

# How to Compile and Run the program: 
Compile by pasting this in your terminal:

Run:
