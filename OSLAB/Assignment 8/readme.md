# Threads & Pipes in Linux
To compile a c program that uses <pthreads.h>
```
gcc -pthread filename.c
```
1. Implement Producer Consumer problem using Semaphore.
### Some Examples of threads in c
#### thread1.c
```c
#include <stdio.h>
#include <pthread.h>
#include<unistd.h>
void* threadFunction(void* args)
{
    int i;
    for(i=1;i<=5;++i)
    {
        printf("I am new thread.\n");
        sleep(1);
    }
}
int main()
{
    pthread_t id;
    int res,i;
    res=pthread_create(&id,NULL,&threadFunction,NULL);
    if(res==0)
    {
        printf("Thread created successfully.\n");
    }
    else
    {
        printf("Thread not created.\n");
        return 0;
    }
    for(i=1;i<=2;++i)
    {
        printf("I am main thread.\n");
        sleep(1);
    }
    return 0;
}
```
#### thread2.c
```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
void *thread_function(void *arg);
char message[] = "Hello World";
int main()
{
    int res;
    pthread_t a_thread;
    void *thread_result;
    res = pthread_create(&a_thread, NULL, thread_function, message);
    if (res != 0)
    {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0)
    {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("Thread joined, it returned: %s\n", (char *)thread_result);
    printf("Message is now: %s\n", message);
    exit(EXIT_SUCCESS);
}
void *thread_function(void *arg)
{
    printf("Thread_function is running. Argument was: %s\n", (char *)arg);
    sleep(3);
    strcpy(message, "Bye!");
    pthread_exit("Thank you for the CPU time");
}
```
### Some Examples of pipes in c
#### pipe1.c
```c
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Writing to external command
int main()
{
    FILE *write_fp;
    char buffer[BUFSIZ + 1];
    sprintf(buffer, "The quick brown fox is sleeping.\n");
    write_fp = popen("cat > newfile.txt", "w");
    if (write_fp != NULL)
    {
        fwrite(buffer, sizeof(char), strlen(buffer), write_fp);
        pclose(write_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}
```
#### pipe2.c
```c
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Communication between child and parent
int main()
{
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "Hello World";
    char buffer[BUFSIZ + 1];
    pid_t fork_result;
    memset(buffer, '\0', sizeof(buffer));
    if (pipe(file_pipes) == 0)
    {
        fork_result = fork();
        if (fork_result == -1)
        {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }
        else if (fork_result == 0) //Child
        {
            sleep(2);
            data_processed = read(file_pipes[0], buffer, BUFSIZ);
            printf("Read %d bytes: %s\n", data_processed, buffer);
            exit(EXIT_SUCCESS);
        }
        else //Parent
        {
            data_processed = write(file_pipes[1], some_data,
            strlen(some_data));
            printf("Wrote %d bytes\n", data_processed);
        }
    }
    exit(EXIT_SUCCESS);
}
```
