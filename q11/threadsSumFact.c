#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sm = 0, prod = 1;

void *sum(void *parm)
{
    printf("Inside sum thread\n");
    for (int i = 1; i <= atoi((char *)parm); i++)
        sm += i;
    printf("Sum thread completed\n");
    return NULL;
}

void *fact(void *parm)
{
    printf("Inside mul thread\n");
    for (int i = 2; i <= atoi((char *)parm); i++)
        prod *= i;
    printf("Mul thread completed\n");
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    pthread_attr_t attr;

    if(argc != 2){
        fprintf(stderr, "Usage %s <number>\n", argv[0]);
        return 1;
    }

    pthread_attr_init(&attr);

    pthread_create(&t1, &attr, sum, argv[1]);
    pthread_create(&t2, &attr, fact, argv[1]);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Inside main thread\n");
    printf("Sum is %d\nProduct is %d\n", sm, prod);
    return 0;
}