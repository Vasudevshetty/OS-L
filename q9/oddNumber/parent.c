#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

typedef struct
{
    int n;
    int arr[100];
} pack_t;

int main()
{
    key_t key = 1234;
    int shmid = shmget(key, sizeof(pack_t), 0666 | IPC_CREAT);
    pack_t *shm_ptr = (pack_t *)shmat(shmid, NULL, 0);
    printf("[PARENT]: Created shared memory with key = %d, id = %d, address = %d\n", key, shmid, shm_ptr);
    printf("[PARENT]: Enter n: ");
    scanf("%d", shm_ptr->n);
    pid_t child_pid;
    if ((child_pid = fork()) == 0)
        execlp("./child", "./child", NULL);
    else
    {
        wait(NULL);
        printf("[PARENT]: Child finsihed executing.\n");
        printf("[PARENT]: The first n odd number are,\n");
        for (int i = 0; i < shm_ptr->n; i++)
            printf("%d ", shm_ptr->arr[i]);
        putchar('\n');
    }

    shmdt((void *)shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);
    printf("[PARENT]: Shared memory delted\n");
    return 0;
}