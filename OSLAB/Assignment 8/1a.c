// Producer consumer problem with binary semaphore (mutex)
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>
#include<signal.h>
#include<semaphore.h>

// number of threads == 2 means ==> 1 producer and 1 consumer
// number of threads == n means ==> n/2 producer & n/2 consumer (if n is even)
// number of threads == n means ==> (n/2)+1 producer & n/2 consumer (if n is odd)
#define THREAD_N 2
// size of the buffer
#define BUFF_SIZE 10

/*
 * mutex is a binary semaphore (MUTEX = MUtual EXclusion)
 * mutex lock means 0 (keep other process waiting from entering into critical section).
 * mutex unlock means 1 (current process completed execution critical section so other process can enter into critical section).
 * mutex is used here so that producer & consumer dosen't update the shared resource (count) at the same time.
 * semaphore is a special type of variable which performs atomic actions.
*/

// declaring a mutex
pthread_mutex_t mutexBuffer;


int buffer[BUFF_SIZE];
int count = 0;

// Handler is used to quit from an infinite loop
void handler(int signal){
    printf("Quitting... [%d]",signal);
    exit(0);
}

void* producer(void* args){
    while(1){
        // generate randome number from 0 to 99
        int x = rand() % 100;
        pthread_mutex_lock(&mutexBuffer);
        // critical section starts 
        if(count < BUFF_SIZE){
            
            buffer[count] = x;
            count++;
            
        }
        else{
            printf("Overflow\t");   // overflow occurs when buffer is full & producer tries to produce
        }
        printf("producer:\t%d\t[count = %d]\n",x,count);    // shows the value produced by producer which was failed to be stored in the buffer
        // critical section ends
        pthread_mutex_unlock(&mutexBuffer);
        
    }
    
}

void* consumer(void* args){
    while(1){
        int y = -1;
        pthread_mutex_lock(&mutexBuffer);
        // critical section starts 
        if(count > 0){
            
            y = buffer[count - 1];
            count--;
            
        }
        else{
            printf("Underflow\t");  // underflow occurs when buffer is empty & consumer tries to consume
        }
        printf("consumer:\t%d\t[count = %d]\n",y,count);    // consumer consumes -1 at underflow
        // critical section ends
        pthread_mutex_unlock(&mutexBuffer);
        
        
    }
    
}

int main(int argc, char const *argv[]){
    printf("[Press Ctrl+C to stop]\n");
    signal(SIGINT,handler);
    
    // array to create n number of threads
	pthread_t threads[THREAD_N];
    // initializing the mutex
    pthread_mutex_init(&mutexBuffer,NULL);
	
	int i;
    // create threads
	for(i=0;i<THREAD_N;i++){
		if(i%2 == 0){
            // assign it to producer
			if(pthread_create(&threads[i],NULL,producer,NULL) != 0){
                perror("Failed to create thread...\n");
			}
		}
        else{
            // assign it to consumer
			if(pthread_create(&threads[i],NULL,consumer,NULL) != 0){
                perror("Failed to create thread...\n");
			}
		}
	}
    // join threads
    for(i=0;i<THREAD_N;i++){
        if(pthread_join(threads[i],NULL) != 0){
            perror("Failed to join thread...");
        }
    }
    // destroying the mutex
    pthread_mutex_destroy(&mutexBuffer);
    return 0;
}
