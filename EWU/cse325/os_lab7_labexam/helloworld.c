#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 8

void *PrintHello(void *threadid)
{
   long taskid;
   sleep(1);
   taskid = *(long *)threadid;
   printf("Hello from thread %ld\n", taskid);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t threads[NUM_THREADS];
  int rc;
  long t,arr[8];
	
  for(t=0;t<NUM_THREADS;t++) {
    printf("Creating thread %ld\n", t);
    arr[t] = t;
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *) &arr[t]);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
      }
  }

  pthread_exit(NULL);
}
