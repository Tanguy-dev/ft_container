# ft_containers Project

![42 Logo](https://img.shields.io/badge/42-Project-brightgreen.svg)

This is the ft_containers project, a part of the curriculum at École 42. The goal of this project is to implement various containers from the C++ Standard Template Library (STL) and gain a deep understanding of their underlying data structures and algorithms.

## Table of Contents

- [Description](#description)
- [Implemented Containers](#implemented-containers)
- [Usage](#usage)

## Description

In this project, we are tasked with re-implementing selected containers from the C++ STL, such as `stack`, `vector` and `map`. The implementation involves creating the data structures from scratch and providing similar functionalities as those offered by the STL.

The project aims to enhance our understanding of data structures, memory management, and algorithm design, while also improving our coding skills in C++.

## Implemented Containers

- `ft::stack`: Container adapter that provides LIFO (Last-In, First-Out) functionality.
- `ft::vector`: Dynamic array that can resize itself automatically.
- `ft::map`: Red-Black Tree-based associative container for key-value pairs.

## Usage

To use the implemented containers, you can include the respective header files in your C++ code and start using them just like you would with the STL containers. For example:

```cpp
#include "ft_vector.hpp"

int main() {
    ft::vector<int> myVector;
    myVector.push_back(42);
    // ... other operations
    return 0;
}
