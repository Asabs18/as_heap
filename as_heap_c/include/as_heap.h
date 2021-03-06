#include "malloc.h"
#include <assert.h>
#include <stdbool.h>

#define NOMANSLANDSIZE 0
// typedef struct _CrtMemBlockHeader {
// // Pointer to the block allocated just before this one:
//     struct _CrtMemBlockHeader *pBlockHeaderNext;
// // Pointer to the block allocated just after this one:
//     struct _CrtMemBlockHeader *pBlockHeaderPrev;
//     char *szFileName;    // File name
//     int nLine;           // Line number
//     size_t nDataSize;    // Size of user block
//     int nBlockUse;       // Type of block(may not need)
//     long lRequest;       // Allocation number
// // Buffer just before (lower than) the user's memory:
//     unsigned char gap[NOMANSLANDSIZE];
// } _CrtMemBlockHeader;

typedef struct _asHeapHeader{
    struct _asHeapHeader *pNextBlockHead;
    struct _asHeapHeader *pLastBlockHead;
    size_t blockSize;
    size_t allocNum;
    bool isFree;
    unsigned char gap[NOMANSLANDSIZE];
} _asHeapFooter;

typedef struct _asHeapFooter {
    struct _CrtMemBlockHeader *pCurrBlockHeader;
} _CrtMemBlockFooter;