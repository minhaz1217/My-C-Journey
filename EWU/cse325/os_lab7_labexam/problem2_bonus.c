/******************************************************************************
* FILE: arraymax.c
* DESCRIPTION:
*   Example code demonstrating decomposition of array processing by
*   distributing loop iterations.  A global max and index of the element is
*   maintained by a mutex variable.
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NTHREADS       5
#define ARRAYSIZE     43
#define ITERATIONS  ARRAYSIZE/NTHREADS

int  max=0, maxIndex = 0, a[ARRAYSIZE];
pthread_mutex_t sum_mutex = PTHREAD_MUTEX_INITIALIZER;




void *runner(void *tid)
{
  int i, start, *mytid, end;
  int myMax, myMaxIndex;

  /* Initialize my part of the global array and keep local sum */
  mytid = (int *) tid;
  start = (*mytid * ITERATIONS);
  end = start + ITERATIONS;
	if(end > ARRAYSIZE){
		//printf("HELLO\n\n\n\n");
		end = ARRAYSIZE;
	}
	myMax = 0;
	for(i = start; i<end;i++){
		if(a[i] > myMax){
			myMax = a[i];
			myMaxIndex = i;
		}
	}
  /* complete this part of the code */
	pthread_mutex_lock(&sum_mutex);
	if(max < myMax){
		max = myMax;
		maxIndex = myMaxIndex;
	}
	pthread_mutex_unlock(&sum_mutex);

  /* printing information after calculating local max */
  printf ("Thread %d doing iterations %d to %d: Max=%d MaxIndex=%d \n",*mytid,start,end-1,myMax,myMaxIndex);

  /* Lock the mutex and update the global sum, then exit */
  /* complete this part of the code */




}


int main(int argc, char *argv[])
{
  int i, start, tids[NTHREADS];

  /* array of threads */
  pthread_t threads[NTHREADS];
  pthread_attr_t attr;
	printf("%d %d %d\n\n\n", ITERATIONS, NTHREADS, ARRAYSIZE);
	//printf("%d %d %d\n\n\n", 5. 5, 5);
  /* randomly generating numbers and printing them */
  printf("Array: \n");
  srand(time(0));
  for(i=0; i<ARRAYSIZE; i++){
    a[i] = rand()%1000;
    printf("%d ", a[i]);
    if(i%10==0 && i/10>=1)
       printf("\n");
  }
  printf("\n");
  /* create threads and Pass each thread its loop offset
     such as 0, 200, 400, 600, 800 */
  for (i=0; i<NTHREADS; i++) {
    tids[i] = i;
    pthread_create(&threads[i], NULL, runner, (void *) &tids[i]);
    }

  /* Wait for all threads to complete then print global sum */
  for (i=0; i<NTHREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  printf ("Done. Max= %d MaxIndex = %d \n", max, maxIndex);

  /* checking the result from main */
  max = a[0];
  maxIndex = 0;
  for (i=1;i<ARRAYSIZE;i++){
    if(max < a[i]){
       max = a[i];
       maxIndex = i;
    }
  }
  printf("Check Max= %d MaxIndex = %d \n",max, maxIndex);

  /* Clean up and exit */
  pthread_mutex_destroy(&sum_mutex);
  pthread_exit (NULL);
}
