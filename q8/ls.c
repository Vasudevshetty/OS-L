#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>

int main(int argc, char* argv[]){
    if (argc < 2){
        printf("You are not passing the directory\n");
        exit(1);
    }

    DIR *dir = opendir(argv[1]);
    if(!dir){
        printf("Cannot open directory %s!\n", dir);
        exit(1);
    }

    struct dirent *dir_entry;
    while((dir_entry = readdir(dir)) != NULL)
        printf("%s\n", dir_entry->d_name);

    closedir(dir);
    return 0;
}