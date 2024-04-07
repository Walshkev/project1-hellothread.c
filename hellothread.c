#include <stdio.h>
#include <pthread.h>

void *run(void *arg)
{
    char *threadName = (char *)arg;
    for (int i = 0; i < 5; i++)
    {
        printf("%s: %d\n", threadName, i);
    }
    return NULL;
}

int main()
{
    pthread_t threads[2];
    char *threadNames[2] = {"thread 1", "thread 2"};

    for (int i = 0; i < 2; i++)
    {
        pthread_create(&threads[i], NULL, run, (char *)threadNames[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        pthread_join(threads[i], NULL);
    }
    printf( "Threads complete!\n");
}