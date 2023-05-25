# Min Heap
The Min Heap is implemented in the minHeap.cpp file. It represents a complete binary tree with the minimum element always at the root.

## Features
- Insertion of elements into the Min Heap using the insert() function.
- Retrieving the minimum element from the Min Heap using the getMin() function.
- Deleting the minimum element from the Min Heap using the deleteMin() function.
- Retrieving the size of the Min Heap using the size() function.

## Usage

To use the Min Heap implementation, follow these steps:
1. Include the 'minHeap.h' header file in your C++ program.
2. Create an instance of the minHeap class: minHeap<DataType> heap;
3. Use the available functions to perform operations on the Min Heap.
  
## Example Usage

```cpp
#include "minHeap.h"

int main() {
    // Create a Min Heap
    minHeap<int> heap;

    // Insert elements
    heap.insert(5);
    heap.insert(3);
    heap.insert(7);

    // Get the minimum element
    int minElement = heap.getMin();

    // Delete the minimum element
    heap.deleteMin();

    // Get the size of the Min Heap
    int heapSize = heap.size();

    return 0;
}
```
## Contributing

Contributions to this repository are welcome.

## License

This project is licensed under the [MIT License]().
