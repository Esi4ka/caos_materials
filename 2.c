#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define BIG_NUM 60000

int a = 0;

static void *plus() {
  for(unsigned i = 0; i < BIG_NUM; ++i) {
    ++a;
  }
  return NULL;
}

static void *minus() {
  for(unsigned i = 0; i < BIG_NUM; ++i) {
    --a;
  }
  return NULL;
}

int main() {
  pthread_t thread[2];

  pthread_create(&thread[0], NULL, &plus, NULL);
  pthread_create(&thread[1], NULL, &minus, NULL);

  // wait threads
  pthread_join(thread[0], NULL);
  pthread_join(thread[1], NULL);

  printf("Result: %d\n", a);

  return 0;
}
