#include "malloc.h"
#include <assert.h>
#include <stdbool.h>

#define NOMANSLANDSIZE 0
typedef struct _CrtMemBlockHeader {
// Pointer to the block allocated just before this one:
    struct _CrtMemBlockHeader *pBlockHeaderNext;
// Pointer to the block allocated just after this one:
    struct _CrtMemBlockHeader *pBlockHeaderPrev;
    char *szFileName;    // File name
    int nLine;           // Line number
    size_t nDataSize;    // Size of user block
    int nBlockUse;       // Type of block(may not need)
    long lRequest;       // Allocation number
// Buffer just before (lower than) the user's memory:
    unsigned char gap[NOMANSLANDSIZE];
} _CrtMemBlockHeader;

// typedef struct _CrtMemBlock {
//     //value stored in this block
//     void* value;
//     //Pointer to the block allocated before this one
//     struct _CrtMemBlock *pPrevBlock;
//     //Pointer to the block allocated after this one
//     struct _CrtMemBlock *pNextBlock;
//     bool isFree;
// } _CrtMemBlock;

typedef struct _CrtMemBlockFooter {
    struct _CrtMemBlockHeader *pCurrBlockHeader;
} _CrtMemBlockFooter;

typedef struct heapInfo_t {
    int allocNumber; //unique allocation number used as key in hash-map
    size_t numBytes; //if this block is free, default numBytes to 0.
    bool isFree;
    //Pointers to the next and previous blocks for drawing purposes
    struct _CrtMemBlockHeader* pNextBlock;
    struct _CrtMemBlockHeader* pPreviousBlock;
} heapInfo_t;