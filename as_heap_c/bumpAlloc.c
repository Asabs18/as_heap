#include <stdlib.h>
#include "bumpAlloc.h"

void* heapPtr = NULL;
void* startPtr;
int capacity = 10000000;

typedef unsigned char byte_t;

void init() {
    heapPtr = malloc(capacity);
    startPtr = heapPtr;
}

void* malloc(size_t size){
    void* newPtr = heapPtr;
    if(size <= capacity){
        heapPtr = (byte_t) heapPtr + size;
    }
    else{
        heapPtr = realloc(heapPtr, size+capacity);
        heapPtr = (byte_t) heapPtr + size;
    }
    return newPtr;
}

void* realloc(void* oldPtr, size_t size){
    void* newPtr = NULL;
    if(size > 0 || oldPtr != NULL){
        void* newPtr = malloc(size);
        memcpy(newPtr, oldPtr, sizeof(&oldPtr));
    }
    return newPtr;
}

void free(){
    free(heapPtr);
}

