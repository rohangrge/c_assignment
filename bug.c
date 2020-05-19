/*#include<stdio.h>
struct temp
{
    char a[10];
    char* b;
}node;
int main(void)
{
    node.a="test";
    node.b="check";
    FILE* fp;
    fp=fopen("testing.txt","w");
    strreplace

    fwrite(&node,sizeof(node),2,fp);
    fclose(fp);
}*/
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
int main(void)
{
    //const char* temp=getenv("PFILE");
    char *temp="hello";
    //setenv("TEST",temp,1);
    putenv("TEST=%s",temp);
    const char* temp1=getenv("TEST");
    printf("%s",temp1);
}