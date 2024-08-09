#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t child_pid, my_pid, parent_pid;
    child_pid = fork();

    if (child_pid < 0)
    {
        printf("Fork failed.\n");
        exit(1);
    }

    if(child_pid==0){
        printf("[CHILD]:This is the child process\n");
        my_pid = getpid();
        parent_pid = getppid();
        printf("[CHILD]: My pid is %d\nMy parent pid is %d\n", my_pid, parent_pid);
        printf("[CHILD]:Exiting\n");
        exit(0);
    }else{
        printf("[PARENT]: This is the parent process\n");
        my_pid = getpid();
        parent_pid = getppid();
        printf("[PARENT]: My pid is %d\nmY parent pid is %d\n", my_pid, parent_pid);
        printf("[PARENT]: Sleep for 10 seconds\n");
        sleep(10);
        printf("[PARENT]: child pid is %d had ended, but it has an entry in process table\n", child_pid);
        printf("[PARENT]: This is a zombie process\n");
    }
    return 0;
}