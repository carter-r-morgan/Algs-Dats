typedef int (*comparator) (const void *item1, const void *item2);
typedef struct heap_t heap_t;

heap_t *alloc_heap(comparator compare, void *data, int size);
void free_heap(heap_t *heap);

void *peek_min(heap_t *heap);
void *pop_min(heap_t *heap);
void push(heap_t *heap, const void *item);
