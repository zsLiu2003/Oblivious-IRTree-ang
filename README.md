# OBIR-tree: Oblivious Index for Spatial Keyword Queries

This repository contains the implementation of the **OBIR-tree (Oblivious Index for Spatial Keyword Queries on Secure Enclaves)**, a privacy-preserving spatial indexing system that enables secure spatial queries while maintaining query privacy through oblivious data structures.

## 📖 Research Paper

This implementation is based on the research paper:
**[OBIR-tree: An Efficient Oblivious Index for Spatial Keyword Queries on Secure Enclaves](https://dl.acm.org/doi/10.1145/3709708)**

## 🏗️ Architecture Overview

The OBIR-tree combines traditional spatial indexing with oblivious RAM (ORAM) techniques to provide:
- **Privacy-preserving spatial queries** - Query patterns are hidden from adversaries
- **Efficient spatial indexing** - Based on R-tree data structure
- **Oblivious data access** - Uses Path ORAM for secure data retrieval
- **Cryptographic security** - AES encryption for data protection

### Core Components

- **R-Tree Implementation** (`RTree.h`, `RTree.c`) - Core spatial indexing structure
- **ORAM Interface** (`include/ORAM.h`) - Abstract oblivious RAM interface
- **Path ORAM** (`include/PathORAM.h`) - Path ORAM implementation with cryptographic primitives
- **P-Tree** (`include/Ptree.h`) - High-level oblivious spatial index integrating R-tree and ORAM
- **Node Management** (`include/Node.h`, `include/Branch.h`) - Data structure components

## 🚀 Getting Started

### Prerequisites

- **C++ Compiler** - G++ with C++11 support or later
- **CryptoPP Library** - For cryptographic operations
  ```bash
  # Ubuntu/Debian
  sudo apt-get install libcrypto++-dev

  # macOS
  brew install cryptopp
  ```

### Building the Project

Since this is a research prototype, compilation is done manually:

```bash
# Clone the repository
git clone <repository-url>
cd Oblivious-IRTree-ang

# Compile the project
g++ -I./include -std=c++11 test/Test_first.cpp include/*.cpp src/*.cpp RTree.c -lcryptopp -o obir_tree

# Run the example
./obir_tree
```

### Project Structure

```
├── RTree.h, RTree.c          # Core R-tree spatial index implementation
├── TBranch.h                 # Tree branch structure definitions
├── include/                  # Header and implementation files
│   ├── ORAM.h               # Abstract ORAM interface
│   ├── PathORAM.h           # Path ORAM implementation
│   ├── Ptree.h              # Main oblivious spatial index
│   ├── Node.h, Branch.h     # Data structure components
│   └── *.cpp                # Implementation files
├── src/                     # Source files
│   └── csprng.cpp          # Cryptographic random number generation
├── test/                    # Test programs
│   └── Test_first.cpp      # Basic usage example
├── data/                    # Sample datasets and queries
│   ├── dataset.txt         # Sample spatial data
│   ├── query*.txt          # Sample query files
│   └── input*.txt          # Input datasets
└── README.md               # This file
```

## 📊 Data Format

### Dataset Format
Spatial points are stored as:
```
keyword x_coordinate y_coordinate
```
Example:
```
vsffi 12.43 43.05
kmalt 32.00 39.17
cnpxf 56.85 4.65
```

### Query Format
Spatial queries are specified as:
```
keyword x_coordinate y_coordinate
```

## 🧪 Usage Example

```cpp
#include "PTree.h"

int main() {
    // Create oblivious spatial index with dataset
    Ptree *tree = new Ptree("dataset.txt");

    // Display index information
    tree->disPlayInfo();

    return 0;
}
```

## 📁 Sample Data

The `data/` directory contains various datasets for testing:

- **dataset.txt** - Small sample dataset (~178KB)
- **dataset2.txt** - Medium dataset (~1.7MB)
- **input.txt** - Large dataset (~70MB)
- **query*.txt** - Various query files for testing
- **output*.txt** - Expected output files

## 🔧 Configuration

Key parameters can be configured in the header files:

- **Dimensions**: Set in `RTree.h` (`DIMS_NUMB = 3`)
- **Page Size**: Configurable in `RTree.h` (`PAGE_SIZE = 512`)
- **ORAM Parameters**: Adjustable in ORAM implementation files
- **Encryption**: AES settings in `PathORAM.h`

## 📈 Performance Metrics

The implementation includes built-in metrics for research evaluation:
- Cache hit rates
- Communication overhead
- Server/client storage costs
- Access pattern analysis