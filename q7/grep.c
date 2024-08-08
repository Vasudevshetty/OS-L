#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char fn[100], pat[10], temp[200];
    printf("Enter file name: ");
    scanf("%s", fn);
    printf("Enter file to be searched: ");
    scanf("%s", pat);
    FILE *fp = fopen(fn, "r");

    while (!feof(fp))
    {
        fgets(temp, 100, fp);
        if (strstr(temp, pat))
            printf("%s\n", temp);
    }
    fclose(fp);
    return 0;
}