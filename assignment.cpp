#include <iostream>
#include <pthread.h>
 
// size of array
#define MAX 1000
 
// maximum number of threads
#define MAX_THREAD 10
 using namespace std;
 int a[MAX]; 
int sum[MAX_THREAD] = { 0 };
int part = 0;
 
void* sum_array(void* arg)
{
 
    // Each thread computes sum of 1/4th of array
    int thread_part = part++;
 
    for (int i = thread_part * (MAX / 10); i < (thread_part + 10) * (MAX / 10); i++)
        sum[thread_part] += a[i];
}
 
// Driver Code
int main()
{
	
	for(int i=0;i<MAX;i++)
	{
		a[i]=i;
	}
 
    pthread_t threads[MAX_THREAD];
 
    // Creating 10 threads
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL);
 
    // joining 4 threads i.e. waiting for all 4 threads to complete
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);
 
    // adding sum of all 10 parts
    int total_sum = 0;
    for (int i = 0; i < MAX_THREAD; i++)
        total_sum += sum[i];
 
    cout << "sum is " << total_sum << endl;
 
    return 0;
}



