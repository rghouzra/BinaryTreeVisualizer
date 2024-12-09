# Print Tree

This project provides functions to print a binary tree in DOT and JSON formats. It includes unit tests using Google Test to verify the functionality of the tree traversal and printing functions.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Building the Project](#building-the-project)
- [Running the Tests](#running-the-tests)
- [Usage](#usage)
- [License](#license)

## Prerequisites

Before you begin, ensure you have the following installed on your system:

- CMake (version 3.10 or higher)
- GCC or Clang compiler
- Git

## Installation

1. **Clone the repository:**

   ```sh
   git clone https://github.com/rghouzra/BinaryTreeVisualizer.git
   cd print_btree_in_dot_format
   ```
2. **Create a build directory:**

   ```sh
   mkdir build
   cd build
   ```
3. **Run CMake:**

   ```sh
   cmake ..
   ```
4. ***Run Make:**

   ```sh
   make
   ```
5. **Run the tests:**

   ```sh
   ctest --output-on-failure
   ```
## vizualization

1. **Run the executable:**

   ```sh
   ./print_tree
   ```
2. **Copy the output

#for dot formats
```
paste the output in https://dreampuf.github.io/GraphvizOnline/
```
#for json formats
```
paste the output in https://jsoneditoronline.org/
```   
