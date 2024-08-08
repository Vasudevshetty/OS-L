#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

typedef struct
{
    int count;
    int fib[100];
} fib_pack_t;

int main()
{
    key_t key = 1234;
    int shmid = shmget(key, sizeof(fib_pack_t), 0666 | IPC_CREAT);
    fib_pack_t *shm_ptr = (fib_pack_t *)shmat(shmid, NULL, 0);
    printf("[CHILD]: Child attached to shared memory with key = %d, id = %d, address = %d\n", key, shmid, shm_ptr);
    shm_ptr->fib[0] = 0;
    shm_ptr->fib[1] = 1;

    for (int i = 2; i < n; i++)
        shm_ptr->fib[i] = shm_ptr->fib[i - 1] + shm_ptr->fib[i - 2];
    printf("[CHILD]: Finsihed generating fibanocci sequence\n");
    return 0;
}
