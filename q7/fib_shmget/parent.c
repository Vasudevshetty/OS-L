#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int count;
    int fib[100];
} fib_pack_t;

int main()
{
    key_t key = 1234;
    int shmid = shmget(key, sizeof(fib_pack_t), 0666 | IPC_CREAT);
    fib_pack_t *shm_ptr = (fib_pack_t *)(shmid, NULL);
    printf("[PARENT]: Created shared memory with key = %d, id = %d, address = %d\n", key, shmid, shm_ptr);
    printf("[PARENT]: Enter n:");
    scanf("%d", shm_ptr->count);

    pid_t child_pid;
    if ((child_pid = fork()) == 0)
        execlp('./child', './child', NULL);
    else
    {
        wait(NULL);
        printf("[PARENT]: Child finished executing\n");
        printf("[PARENT]: The first n odd numbers are, \n");
        for (int i = 0; i < n; i++)
            printf("%d ", shm_ptr->fib[i]);

        putchar('\n');
    }

    shmdt((void *)shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);
    printf("[PARENT]: Shared memory deleted\n");
    return 0;
}