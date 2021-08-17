#include <stdlib.h>
#include "bumpAlloc.h"

void* heapPtr = NULL;
int capacity = 0;
int delta = 10000000; 

typedef unsigned char byte_t;

void* _realloc(void* oldPtr, size_t size){
    realloc(oldPtr, size);
}

void* _malloc(size_t size){
    malloc(size);
}

void* malloc(size_t size){
    void* newPtr = heapPtr;
    if(size <= capacity){
        heapPtr = (byte_t*) heapPtr + size;
        capacity -= size;
    }
    else{
        assert(size < capacity);
        capacity += delta;
        void* tempPtr = _realloc(heapPtr, capacity); 
        assert(tempPtr != NULL); 
        assert(tempPtr == heapPtr);
    }
    return newPtr;
}

void* realloc(void* oldPtr, size_t size){
    void* newPtr = NULL;
    if(size > 0 || oldPtr != NULL){
        void* newPtr = _malloc(size);
        memcpy(newPtr, oldPtr, sizeof(&oldPtr));
    }
    return newPtr;
}

void free(void* ptr){
    return;
}

