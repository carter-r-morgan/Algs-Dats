/*
 *
 *
 */

/*********************
 * TYPE DECLARATIONS *
 *********************/

/*
 * Function type used to compare items within a heap.
 *
 * Input: pointers to 2 items in a heap.
 * Return: (-) if item1 < item2, (+) if item1 > item2, 0 otherwise.
 * Note: A comparator function is provided by the user on heap allocation to
 *   specify how items should be compared. This function must form a total order
 *   over the elements of the heap and must be a pure function.
 */
typedef int (*comparator) (const void *item1, const void *item2);

/*
 * Struct type which represents a heap.
 */
typedef struct heap_t heap_t;

/***************************
 * ALLOCATORS/DEALLOCATORS *
 ***************************/

/*
 * Allocate a new heap.
 *
 * Input:
 *   - compare: function used to compare items within the heap.
 *   - data: (optional) Pointer to an existing buffer. The data in that buffer
 *       is used to initialize the heap & the heap takes ownership over the
 *       buffer. If not null, the size of the buffer must also be given.
 *   - size: (optional) If an existing buffer is given, the size of that buffer.
 *       else, the size to initialize the heap with. Values <= 0 will be ignored.
 */
heap_t *alloc_heap(comparator compare, void **data, int size);

/*
 * Free the given heap
 */
void free_heap(heap_t *heap);

/********************
 * MEMBER FUNCTIONS *
 ********************/

/*
 * Return a pointer to the smallest item in the heap w/o removing it.
 */
void *peek_min(heap_t *heap);

/*
 * Return a pointer to the smallest item in the heap and remove it.
 */
void *pop_min(heap_t *heap);

/*
 * Add the given item to the heap.
 */
void push(heap_t *heap, void *item);
