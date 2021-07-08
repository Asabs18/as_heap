#pragma once

typedef unsigned char byte_t; //TEMP IN ORDER TO BUILD AND WRITE HEADERS

//-----Check if the Heap is Coalesced-----//
bool _isHeapCoalesced(byte_t* heap);
/*This function will walk the heap by starting at the first block header and checking
if it is free, if so move to the next header and check if it is free, if two free blocks
are in a row then something went wrong with Coalescing the heap and False will be returned.
if the end of the heap is reached without finding two free blocks in a row, return True*/
//-----Check how fragmented the heap is-----//
int _amountOfFragments(byte_t* heap);
/*This function will walk the heap and check the payload of each block. This function 
will then check to see how fragmented the payload is(how to do this is TBD) and add 
that number to a running count of fragmented bytes. This function will then return this 
number*/
//-----Check how big the heap is-----//
int _heapSize(byte_t* heap);
/*This function will walk the heap adding the total size of each block including headers and
footers to a running variable which will be returned at the end. This function is only usefull
if the heap runs out of memory and needs to make a call to the OS to grab more*/
//-----Check if the heap overruns its specified block of memory-----//
int _checkHeapOverun(byte_t* heap);
/*This function uses the noMansLand values in order to see if any memory on the heap 
is being overwritten past the amount of memory provided. (Need to discuss exactly how
this would work)*/
