/*
 *
 *
 */

#include <stdlib.h>
#include "heap.h"

const int DEFAULT_SIZE = 64;
const int RESIZE_FACTOR = 2;
const int BRANCH_FACTOR = 4;

struct heap_t {
  int size;
  int buffer_size;
  void **data;
  comparator compare;
};

void heapify(heap_t *heap) {

}

void resize(heap_t *heap) {

}

void bubble(heap_t *heap, int index) {

}

void sift(heap_t * heap, int index) {

}

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
 *       else, the size to initialize the heap's buffer with.
 */
heap_t *alloc_heap(comparator compare, void **data, int size) {
  if (!compare) return NULL;

  heap_t *heap = (heap_t*)malloc(sizeof(heap_t));
  *heap = (heap_t){size, size, data, compare};

  if (data == NULL) {
    heap->size = 0;
    heap->buffer_size = size ? size : DEFAULT_SIZE;
    heap->data = malloc(heap->buffer_size * sizeof(void*));
  }
  else {
    if (size <= 0) return NULL;
    heapify(heap);
  }

  return heap;
}

/*
 * Free the given heap
 */
void free_heap(heap_t *heap) {
  for (int i = 0; i < heap->size; i++)
    free(heap->data[i]);
  free(heap->data);
  free(heap);
}

/********************
 * MEMBER FUNCTIONS *
 ********************/

/*
 * Return a pointer to the smallest item in the heap w/o removing it.
 */
void *peek_min(heap_t *heap) {
  if (heap->size == 0) return NULL;
  return heap->data[0];
}

/*
 * Return a pointer to the smallest item in the heap and remove it.
 */
void *pop_min(heap_t *heap) {
  if (heap->size == 0) return NULL;
  void *min = heap->data[0];

  heap->data[0] = heap->data[--heap->size];
  sift(heap, 0);
}

/*
 * Add the given item to the heap.
 */
void push(heap_t *heap, void *item) {
  if (heap->size >= heap->buffer_size) resize(heap);

  heap->data[heap->size] = item;
  bubble(heap, heap->size++);
}
