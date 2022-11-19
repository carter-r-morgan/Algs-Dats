#include "heap.h"
#include "lib/CuTest.c"
#include <string.h>

/*
Alloc
compare=null -> null
data!=null & size <= 0 -> null
data=null & size<=0 -> default capacity, size=0
data=null & size>0 -> specified capacity, size=0
data!=null & size>0 -> specified buffer & capacity, size=0

push(x)
peek() -> x
pop() -> x
peek() -> !x


Free

Push

Pop

Peek

*/



int comp_int(const void *a, const void *b) {
  return *((int*)a) - *((int*)b);
}

int comp_str(const void *a, const void *b) {
  return strcmp((char*)a, (char*)b);
}

void test(CuTest *tc) {

}


CuSuite* heap_get_suite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test);
  // ...
  return suite;
}

void RunAllTests(void) {
  CuString *output = CuStringNew();
  CuSuite* suite = CuSuiteNew();

  CuSuiteAddSuite(suite, heap_get_suite());

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);
}

int main(void) {
  RunAllTests();
}
