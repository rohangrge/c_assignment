#include<stdio.h>
#include<string.h>
struct upass
{
    char* user;
    char* epwd;
    
};
int main(void)
{
    FILE* fp;
    struct upass db;
    char* token;
    int i=0;
    fp=fopen("passwd.txt","r");
    char buf[1000];
    fgets(buf,sizeof(buf),fp);
    token=strtok(buf,":");
   // db.user=token[0];
    //db.epwd=token[1];
    printf("%s\n",token);
    db.user=token;
    token=strtok(NULL,":");
    db.epwd=token;
    printf("user name%s\n",db.user);
    printf("passwd%s\n",db.epwd);
}