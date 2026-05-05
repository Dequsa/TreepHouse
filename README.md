# TreepHouse

[![C++](https://img.shields.io/badge/C%2B%2B-20-blue.svg)](https://isocpp.org/)
[![CMake](https://img.shields.io/badge/CMake-4.0+-green.svg)](https://cmake.org/)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A high-performance command-line application implementing a **Treap** (Tree + Heap) data structure — a randomized binary search tree that combines BST ordering with heap priorities for efficient operations.

## Features

- **Insert/Update** — Add items by ID or update existing prices in O(log n) expected time
- **Delete** — Remove items by ID with automatic rebalancing
- **Count** — Get total number of items in O(1) time
- **Range Sum** — Compute sum of values for ID ranges in O(log n) time using subtree metadata
- **Self-Balancing** — Uses random priorities and tree rotations to maintain balance
- **Optimized Queries** — Each node maintains subtree aggregates (`sum`, `min_id`, `max_id`, `sub_tree_size`) for efficient pruning

## Prerequisites

- **C++20-compatible compiler**: GCC 11+, Clang 13+, or MSVC 2022+
- **CMake**: Version 4.0 or later

## Getting Started

### Build

```bash
# Clone the repository
git clone https://github.com/Dequsa/TreepHouse.git
cd TreepHouse

# Create and enter build directory
mkdir build && cd build

# Configure and build
cmake ..
cmake --build .
```

### Usage

Run the executable:

```bash
./TreepHouse
```

The program prompts for the number of operations, then accepts commands in the following format:

| Command | Arguments | Description |
|---------|-----------|-------------|
| `A` | `<id> <price>` | Insert item (or update price if ID exists) |
| `D` | `<id>` | Delete item by ID |
| `C` | — | Print total item count |
| `S` | `<min_id> <max_id>` | Print sum of prices in ID range |

### Example

```
3
A 1 50
A 2 75
S 1 2
```

**Output:**
```
125
```

## Project Structure

```
TreepHouse/
├── CMakeLists.txt          # Build configuration
├── main.cpp                # Entry point
├── Node.h / Node.cpp       # Treap node with subtree metadata
├── Tree.h / Tree.cpp       # Treap operations (insert, delete, rotate, range sum)
└── InputHandler.h / .cpp   # CLI interface
```

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## Author

**Kacper Marciniak**

- GitHub: [@Dequsa](https://github.com/Dequsa)
- Email: marciniak.kacperek@gmail.com

## License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.
