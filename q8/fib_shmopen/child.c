#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <sys/stat.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    void *ptr;
    int shm_fd = shm_open("VSS", O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1)
    {
        perror("shm_open failed");
        exit(1);
    }

    ftruncate(shm_fd, 4096);
    ptr = mmap(0, 4096, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED)
    {
        perror("mmap faield.");
        exit(1);
    }

    int i = atoi(argv[1]);
    int n1 = 0, n2 = 0;
    sprintf(ptr, "%d %d", n1, n2);
    ptr += strlen(ptr);
    int k = 2;
    while (k < i)
    {
        int n3 = n1 + n2;
        sprintf(ptr, "%d ", n3);
        n1 = n2;
        n2 = n3;
        k++;
        ptr += strlen(ptr);
    }
}