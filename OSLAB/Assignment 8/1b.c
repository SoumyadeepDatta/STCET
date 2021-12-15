// Producer consumer problem with binary semaphore (mutex) & counting semaphore
// To avoid overflow & underflow
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>
#include<signal.h>
#include<semaphore.h>

/*
 * sem_wait => decreases the value by 1 each time
 * if it reaches to zero, waits for the semaphore to be > 0 again 
 * sem_post => increases the value by 1 each time
 * semaphore is an unsigned int so maximum value of its is maximum value of unsigned int
*/

#define THREAD_N 2
#define BUFF_SIZE 10

// declaring counting semaphore
// empty => to keep track of vacant slots in the buffer (initial value = maximum size of the buffer because all slots are empty at first)
// full => to keep track of occupied slots in the buffer (initial value = 0 because all slots are empty at first so no slots are filled)

sem_t full;
sem_t empty;

pthread_mutex_t mutexBuffer;

sem_t sem;
int buffer[BUFF_SIZE];
int count = 0;

void handler(int signal){
    printf("Quitting... [%d]",signal);
    exit(0);
}

void* producer(void* args){
    while(1){
        int x = rand() % 100;
        sem_wait(&empty); // decrease the value of empty slot by 1
        // as producer will be producing an item
        // if it becomes 0 that means no empty slot is left 
        // so producer has to wait through sem_wait() until & unless there is/are 1/many empty slot(s) 
        // this way we can avoid overflow
        pthread_mutex_lock(&mutexBuffer);
        
        
        if(count < BUFF_SIZE){
            
            buffer[count] = x;
            count++;
            
        }
        else{
            printf("Overflow\t");
        }
        printf("producer:\t%d\t[count = %d]\n",x,count);
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&full); // increase the number of filled slot by 1 
        // because producer has produced an item & that is stored into a slot
    }
    
}

void* consumer(void* args){
    while(1){
        int y = -1;
        sem_wait(&full);// decrease the value of full slot by 1
        // as consumer will be consuming an item
        // if it becomes 0 that means no full slot is left which means all slots are empty
        // so consumer has to wait through sem_wait() until & unless there is/are 1/many filled slot(s)
        // this way we can avoid underflow 
        pthread_mutex_lock(&mutexBuffer);
        if(count > 0){
            
            y = buffer[count - 1];
            count--;
            
        }
        else{
            printf("Underflow\t");
        }
        printf("consumer:\t%d\t[count = %d]\n",y,count);
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&empty);// increase the number of empty slot by 1 
        // because consumer has consumed an item from the buffer & that slot became empty
        
    }
    
}

int main(int argc, char const *argv[]){
    printf("[Press Ctrl+C to stop]\n");
    signal(SIGINT,handler);
    srand(time(NULL));
	pthread_t threads[THREAD_N];
    pthread_mutex_init(&mutexBuffer,NULL);
    // sem_init(name,0 for threads and 1 for process,initial value)
	sem_init(&full,0,0); 
    sem_init(&empty,0,BUFF_SIZE);

	int i;
	for(i=0;i<THREAD_N;i++){
		if(i%2 == 0){
			if(pthread_create(&threads[i],NULL,producer,NULL) != 0){
                perror("Failed to create thread...\n");
			}
		}
        else{
			if(pthread_create(&threads[i],NULL,consumer,NULL) != 0){
                perror("Failed to create thread...\n");
			}
		}
	}
    for(i=0;i<THREAD_N;i++){
        if(pthread_join(threads[i],NULL) != 0){
            perror("Failed to join thread...");
        }
    }
    // destroy all semaphores at last
    sem_destroy(&empty);
    sem_destroy(&full);
    
    pthread_mutex_destroy(&mutexBuffer);
    return 0;
}
