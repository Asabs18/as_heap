# How the Heap and the Heap_State Parallel Structure will work:

## Heap:

- Double-Linked-List Structure
- Has a header, container, and footer
- The header contains information such as free or allocated and size.
- The footer contains the address of the header
- the container stores the users information when allocated and the header information when freed
- The heap is checked and maintained by a suite of heap check functions still to be implemented.

## Heap-Parallel Structure:
- This structure will be a hash-table implemented through UT-hash
- This will have a key(allocation number) and a value(Important info struct)
- This structure will communicate with the heap by calling a function that reads the heap and updates the Hash-Table accordingly. This function will be called right after the heap-check function suite.