#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("File not entered\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if(!fp){
        printf("File doesn't exist\n");
        exit(1);
    }

    char ch;
    while((ch = fgetc(fp)) != EOF)
        printf("%c", ch);

    fclose(fp);
    printf("\n");
}