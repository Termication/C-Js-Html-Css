#include <stdio.h>

int main(void)
{
    FILE *filename = fopen("file.text", "a");

    fprintf(filename, "This is a output text");

    fclose(filename);

    return 0;
}