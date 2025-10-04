# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is an implementation of the **OBIR-tree (Oblivious Index for Spatial Keyword Queries on Secure Enclaves)** as described in the research paper. The project combines spatial indexing with oblivious data structures for privacy-preserving spatial queries.

## Core Architecture

### Main Components

1. **R-Tree Implementation** (`RTree.h`, `RTree.c`)
   - Core spatial indexing structure with 3-dimensional support
   - Provides standard R-tree operations: insert, delete, search
   - Uses configurable page size (512 bytes default) and branching factor

2. **ORAM Interface** (`include/ORAM.h`)
   - Abstract base class defining the oblivious RAM interface
   - Key methods: `get()`, `put()`, `bulkLoad()`, `batchAccess()`
   - Provides size and performance metrics tracking

3. **Path ORAM** (`include/PathORAM.h`, `include/PathORAM.cpp`)
   - Implements Path ORAM scheme for oblivious data access
   - Uses CryptoPP library for AES encryption/decryption
   - Provides cryptographic primitives and random block generation

4. **P-Tree** (`include/Ptree.h`, related files)
   - Higher-level tree structure that likely integrates R-tree with ORAM
   - Main entry point for the oblivious spatial index

5. **Supporting Components**
   - `include/Node.h/.cpp` - Node structure definitions
   - `include/Branch.h` - Branch/edge definitions
   - `include/RandomForOram.h/.cpp` - Random number generation for ORAM
   - `src/csprng.cpp` - Cryptographically secure random number generation

### Key Design Patterns

- **Template-based**: Heavy use of C++ templates for generic data structures
- **Abstract interfaces**: ORAM base class allows for different ORAM implementations
- **Privacy-first**: All data structures designed with obliviousness in mind
- **Configurable parameters**: Dimensions, page sizes, and security parameters are configurable

## Build Instructions

This project appears to be a research prototype without a standard build system. To compile:

1. **Dependencies**: Requires CryptoPP library for cryptographic operations
2. **Manual compilation**: No Makefile or CMake found - compile manually with g++
3. **Example compilation**:
   ```bash
   g++ -I./include -std=c++11 test/Test_first.cpp include/*.cpp src/*.cpp RTree.c -lcryptopp -o obir_tree
   ```

## Testing

- Test files located in `test/` directory
- `test/Test_first.cpp` provides a basic example using dataset.txt
- Sample datasets in `data/` directory (dataset.txt, input.txt, query files)

## Key Files to Understand

1. **Start here**: `test/Test_first.cpp` - Simple usage example
2. **Core spatial index**: `RTree.h` and `RTree.c` - R-tree implementation
3. **Oblivious interface**: `include/ORAM.h` - Base ORAM interface
4. **Main tree**: `include/Ptree.h` - High-level oblivious spatial index
5. **Crypto**: `include/PathORAM.h` - Encryption and ORAM primitives

## Development Notes

- This is a research implementation focused on privacy-preserving spatial queries
- Code uses both C and C++ (R-tree in C, ORAM components in C++)
- Heavy focus on oblivious data structures and cryptographic security
- Performance metrics built-in for research evaluation