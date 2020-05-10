#include<stdio.h>
#include<string.h>
int main(void)
{
    FILE* fp;
    fp=fopen("tmp.txt","a+");
    char buf[200];
    fgets(buf,200,fp);
    printf("%s",buf);
}