# simple-queue-tdd

[![Test Queue](https://github.com/samuel-reedy/simple-queue-tdd/actions/workflows/ci.yml/badge.svg)](https://github.com/samuel-reedy/simple-queue-tdd/actions/workflows/ci.yml)

## Design Choices

### Data Structure
- **Queue**: Implemented as a linked list to allow for dynamic memory allocation.
- **Node**: Each node contains data and a pointer to the next node, necessary for the linked list structure.

### Test Framework
- **Google Test**: 
    - Most familiar testing framework.
    - Suitable for C/C++.
- **Test Fixture**: Allows the queue to be easily reused in multiple tests without the need to repeat code/initialisation.

## Build and Run
1. **Clone Repo**:
    ```sh
    git clone https://github.com/samuel-reedy/simple-queue-tdd.git
    cd simple-queue-tdd
    ```

2. **Build**:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Test**:
    ```sh
    ctest -V
    ```