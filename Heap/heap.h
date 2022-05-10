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

heap_t *alloc_heap(comparator compare, void *data, int size);
void free_heap(heap_t *heap);

/********************
 * MEMBER FUNCTIONS *
 ********************/

void *peek_min(heap_t *heap);
void *pop_min(heap_t *heap);
void push(heap_t *heap, const void *item);
