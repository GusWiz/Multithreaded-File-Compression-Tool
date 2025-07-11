# Multithreaded-File-Compression-Tool
This tool allows you to compress a files

# Structure of the Program:

multithreaded-compressor/
│
├── CMakeLists.txt                 # (If using CMake) Build instructions
├── README.md                      # Project overview, usage, etc.
├── main.cpp                       # Main entry point (CLI, argument parsing)
│
├── include/                       # Header files
│   ├── compressor.hpp             # Compression interface (abstract or base)
│   ├── huffman.hpp                # Huffman coding declarations
│   ├── lz77.hpp                   # LZ77 coding declarations
│   ├── thread_pool.hpp            # Thread pool or async utilities
│   ├── file_io.hpp                # File read/write functions
│   └── bit_utils.hpp              # Bit-level helpers (packing, shifting)
│
├── src/                           # Source files (implementation)
│   ├── compressor.cpp             # Shared compression base implementation
│   ├── huffman.cpp                # Huffman encoding/decoding logic
│   ├── lz77.cpp                   # LZ77 encoding/decoding logic
│   ├── thread_pool.cpp           # Optional thread pool implementation
│   ├── file_io.cpp                # File reading/writing logic
│   └── bit_utils.cpp              # Bit-level function implementations
│
├── tests/                         # Unit tests or test files
│   ├── test_data.txt              # Sample input for compression
│   ├── test_compression.cpp       # Tests for compression accuracy
│   └── test_multithreading.cpp    # Tests for parallel chunk handling
│
└── build/                         # Output directory for compiled binaries

# Purpose of each program:
🧠 Root-Level Files
main.cpp

Orchestrates the compression/decompression process.

Parses command-line arguments (e.g., file name, algorithm, mode).

Delegates tasks to the appropriate compression class and manages thread use.

CMakeLists.txt

Defines how to build the project (compile sources, link files, set flags).

Specifies dependencies and output binary details.

README.md

Explains what the project does.

Describes how to build and run the tool.

May include benchmarks, algorithm notes, or performance tips.

📁 include/ (Header Files)
compressor.hpp

Defines a general compression interface or abstract base class.

Declares common methods like compress(), decompress(), etc.

huffman.hpp

Declares functions and classes specific to the Huffman algorithm.

Contains tree structure definitions, encoding maps, and helper methods.

lz77.hpp

Declares functions and classes for the LZ77 compression algorithm.

Includes sliding window logic and match-finding strategies.

thread_pool.hpp

Declares a custom thread pool or utilities using std::thread or std::async.

Manages the scheduling and reuse of worker threads.

file_io.hpp

Declares functions for reading from and writing to files in binary mode.

Supports chunking files for parallel processing.

bit_utils.hpp

Declares low-level helpers for bit manipulation.

Useful for packing/unpacking data during encoding.

📁 src/ (Implementation Files)
compressor.cpp

Implements the abstract compression interface.

May include shared logic (e.g., chunk management, input validation).

huffman.cpp

Implements the Huffman compression and decompression routines.

Handles tree construction, encoding, and decoding.

lz77.cpp

Implements LZ77 compression logic: window scanning, match-length encoding, etc.

Includes decompression logic as well.

thread_pool.cpp

Implements multithreading logic: worker threads, task queue, etc.

Manages splitting work and collecting results from parallel compression.

file_io.cpp

Implements file operations such as opening, reading in chunks, writing output.

May include helpers for determining file size, chunk boundaries, etc.

bit_utils.cpp

Implements bit-level manipulation functions.

Useful for converting between bits and bytes during compression.

📁 tests/ (Testing & Sample Data)
test_data.txt

Sample input file for testing your compression tool.

Helps test for correctness and edge cases.

test_compression.cpp

Tests Huffman and LZ77 implementations.

Ensures compression → decompression returns original data.

test_multithreading.cpp

Tests concurrent file chunk processing.

Checks for race conditions, data loss, or corruption during parallel execution.

# How to Compile and Run the program: 
Compile by pasting this in your terminal:
gcc -o testing_file_io.exe src/testing_file_io.cpp src/file_io.cpp -I include -lstdc++

Run:
.\testing_file_io.exe