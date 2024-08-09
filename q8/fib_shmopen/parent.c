#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, shm_fd;
    void *ptr;

    if (argc == 2)
    {
        sscanf(argv[1], "%d", &i);
    }
    else
    {
        printf("Errror: Minmium of two arguments must be passed");
        exit(0);
    }

    pid_t pid = fork();

    if (pid == 0)
        execlp("./child", "./child", argv[1], NULL);
    else{
        wait(NULL);
        printf("Parent: Child ocmpleted\n");
        shm_fd = shm_open("VSS", O_RDONLY, 0666);
        if(shm_fd == -1){
            perror("shm_open fialed");
            exit(1);
        }

        ptr = mmap(0, 4096, PROT_READ, MAP_SHARED, shm_fd, 0);
        if(ptr == MAP_FAILED){
            perror("mmap failed");
            exit(1);
        }

        printf("Parent printing: \n%s", (char *)ptr);

        if(shm_unlnk("VSS") == -1){
            perror("shm_unlnk failed");
            exit(1);
        }

        munmap(ptr, 4096);
        close(shm_fd);
    }
    return 0;
}