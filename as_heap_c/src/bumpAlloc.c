#include <stdlib.h>
#include <assert.h>
#include "bumpAlloc.h"


#define AS_ALIGN 16

typedef unsigned char byte_t;
union header{
	struct header_s {
		size_t size;
	} s;
	unsigned char _[AS_ALIGN];
} header_t;

#define HEAD_SIZE sizeof(union header)
#define GET_HEADER(mem) \
	((struct header_s *)((char *)(mem) - sizeof(union header)))

void* heapPtr = NULL;
int capacity = 0;
const int delta = 10000000; 

void* asBumpMalloc(size_t size){
    void* newPtr = heapPtr;
    if(size <= capacity){
        if(size == 0){
            newPtr = NULL;
        }
        else{
            heapPtr = (byte_t*) heapPtr + size + HEAD_SIZE;
            capacity -= size;
        }
    }
    else{
        assert(size < delta);
        capacity += delta;
        void* tempPtr = realloc(heapPtr, capacity); 
        assert(tempPtr != NULL); 
        assert(tempPtr == heapPtr || heapPtr == NULL);
        heapPtr = tempPtr;
        if(size > 0){
            heapPtr = (byte_t*) heapPtr + size + HEAD_SIZE;
            capacity -= size;
        }
        newPtr = heapPtr;
    }
    return newPtr;
}

void* asBumpRealloc(void* oldPtr, size_t size){
    void* newPtr = NULL;
    if(size > 0 || oldPtr != NULL){
        void* newPtr = malloc(size);
        memcpy(newPtr, oldPtr, &GET_HEADER(oldPtr)->size);
    }
    return newPtr;
}

void asBumpFree(void* ptr){
    return;
}



// void* _realloc(void* oldPtr, size_t size){
//     realloc(oldPtr, size);
// }

// void* _malloc(size_t size){
//     malloc(size);
// }