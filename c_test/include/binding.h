#define AS_BUMP_HEAP 
#if defined(CRT_HEAP)
    #define mallocSUT malloc
    #define reallocSUT realloc
    #define freeSUT free
#elif defined(AS_BUMP_HEAP)
    #define mallocSUT asBumpMalloc
    #define reallocSUT asBumpRealloc
    #define freeSUT asBumpFree
#elif defined(AS_HEAP)
    #define mallocSUT asMalloc
    #define reallocSUT asRealloc
    #define freeSUT asFree
#elif defined(TURKEY_HEAP)
    #define mallocSUT tkMalloc
    #define reallocSUT tkRealloc
    #define freeSUT tkFree
#else
    #error "Unkown Heap"
#endif