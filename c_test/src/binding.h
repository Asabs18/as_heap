//#define mallocSUT malloc
#ifndef mallocSUT
    #define mallocSUT asBumpMalloc
#endif

//#define reallocSUT realloc
#ifndef reallocSUT
    #define reallocSUT asBumpRealloc
#endif

//#define freeSUT free
#ifndef freeSUT
    #define freeSUT asBumpFree
#endif