typedef unsigned char byte_t;
typedef struct _header header_t;
typedef struct _footer footer_t;

header_t* head;
footer_t* tail;

#define INIT_HEAP_SIZE	(1024 * 1024)
// *** initialize heap
// allocate space
byte_t* heap = os_malloc( INIT_HEAP_SIZE );
// setup header
head = (header_t*) heap;
head->whatever-fields-are-defined-on-header_t;
// data/payload (user's data) variable in length
// setup footer
foot = INIT_HEAP_SIZE - sizeof( footer_t );
foot->whatever-fields-are-defined-on-footer_t;

// *** malloc()
head->next; // next available block
// hypothetical...
footer_t* footer = header->next + header->block_size + sizeof( header_t );

/* heap:0:N
alloc 1: block 0
0: header_t	// links to header at N/2
 user's data
F; footer*
// ...
N/2: header_t
 user's data
Fx: footer

N:
*/