#include<stdio.h>
#include<string.h>
int main(void)
{
    char a[]="this is a test";
    char* b=strtok(a," ");
    printf("%s",b);
}