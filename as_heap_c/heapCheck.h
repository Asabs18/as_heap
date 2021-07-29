#pragma once
#include <stdbool.h>
#include <stdlib.h>

typedef unsigned char byte_t; //Change to const void*

typedef struct checkOutput{
    int fragments;
    bool isOverrun;
    //...
} checkOutput_t;

//-----Check if the Heap is Coalesced-----//
bool _isHeapCoalesced(void* heap); //need more robust return type
/*This function will walk the heap by starting at the first block header and checking
if it is free, if so move to the next header and check if it is free, if two free blocks
are in a row then something went wrong with Coalescing in the heap and False will be returned.
if the end of the heap is reached without finding two free blocks in a row, return True*/
//TODO: In a row needs to be defined


//-----Check how fragmented(internal) the heap is-----//
checkOutput_t _amountOfInternalFragments(void* heap); //need more robust return type
/*This function will walk the heap and check the payload of each block. This function 
will then check to see how fragmented the payload is(difference between requested and actual size) and add 
that number to a running count of fragmented bytes. This function will then return this 
number*/

checkOutput_t _amountOfExternalFragments(void* heap);
/*DISCUSS*/

//-----Check if the heap overruns its specified block of memory-----//
checkOutput_t _checkHeapOverun(void* heap);
/*This function uses the noMansLand values in order to see if any memory on the heap 
is being overwritten past the amount of memory provided. (Need to discuss exactly how
this would work)*/

//-----Check how big the heap is-----//
// size_t _heapSize(byte_t* heap);
/*This function will walk the heap adding the total size of each block including headers and
footers to a running variable which will be returned at the end. This function is only usefull
if the heap runs out of memory and needs to make a call to the OS to grab more*/