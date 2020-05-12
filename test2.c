#include<stdio.h>
#include<stdlib.h>
struct spwd
{
    char* suser;
    char* spwd;
}
int main(void)
{
    FILE* ts;
    struct spwd s3;
    char* tok;
    char* buffer;
    ts=fopen("shadow.txt","a+");
    fgets(buffer,sizeof(buffer),ts);
    tok=strtok(buffer,":");
    s3.suser=tok;
    tok=strtok(NULL,":");
    s3.spwd=tok;
}