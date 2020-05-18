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
int main(void)
{
    const char* temp=getenv("PFILE");
    printf("%s",temp);
}