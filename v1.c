#include<stdio.h>
#include<string.h>
//#include<pwd.h>
//#include<system.h>
#include<stdlib.h>
#include<unistd.h>
//#include<conio.h>
struct upass
{
    char* user;
    char* epwd;
    
};
struct spwd
{
    char* suser;
    char* spwd;
};
void cmd();
void chcmd();
void chkpwd();
void chngpwd();
char* decrypt(char*,char*);
int main(void)
{
    FILE* fp;
    cmd();
}



void cmd()
{   
    char com[50],b[20];
    char* p;
    printf("Enter your command\n");
    scanf("%s",com);
    char a[50]="passwd";    
    if(strcmp(a,com)==0)
    {
        chkpwd();
        
    }
    else
    {
      printf("Command '%s' not found\n",com);
      cmd();
    }
}
void chkpwd()
{
    char checker[40];
    char inp[40];
    char *udata;
    char* cpass;
    char* uname;
    FILE* fp;
    struct upass db;
    char* token;
    int i=0;
    fp=fopen("passwd.txt","r");
    char buf[1000];
    fgets(buf,sizeof(buf),fp);
    token=strtok(buf,":");
    db.user=token;
    token=strtok(NULL,":");
    db.epwd=token;
    uname=db.user;
    fclose(fp);
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
    char* decrypte=decrypt(db.epwd,s3.spwd);
    

    
     printf("Changing password for %s\n",uname);//get the user name from the file 
    //printf("\nCurrent password:");
    cpass=getpass("Current password:");
    if(strcmp(decrypte,cpass)==0)
    {
        chngpwd();
    }
    else
    {
        printf("passwd: Authentication token manipulation error");
        printf("\npasswd:password unchanged\n");

    }
    

}
void chngpwd()
{

}
char* decrypt(char* key,char* msg)
{
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;
    for(i = 0; i < msgLen; ++i)
    {
        decryptedMsg[i] = (((msg[i] - key[i]) + 26) % 26) + 'A';
    } 
 
    decryptedMsg[i] = '\0';
return decryptedMsg;
 
}

    