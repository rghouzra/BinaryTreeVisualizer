# readme

# Print bTree in Dot Format

The "print_tree_in_dot_format" project is a C program that generates a DOT language file for visualizing binary tree structures using the Graphviz software. The program takes in a tree structure in the form of nodes and edges and outputs a DOT file that can be used to generate an image of the tree.

## Installation

To use this program, you'll need to have Graphviz installed on your machine. You can download Graphviz from the official website [here](https://graphviz.org/download/).

To compile the program, you can use the included Makefile. The Makefile creates a static library called `libprint_tree.a`, which you can link to your own C programs. To create the library run the following command:

```
make

```

## Usage
```
bash runTests.sh