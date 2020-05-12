#include<stdio.h>
#include<string.h>
//#include<pwd.h>
//#include<system.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
//#include<conio.h>
struct upass
{
    char* user;
    char *epwd;
    
};
struct spwd
{
    char* suser;
    char *spwde;
};
void cmd();
void chcmd();
void chkpwd();
void chngpwd();
char* decrypt(char*,char*);
int main(void)
{
    cmd();
}
void cmd()
{   
    char com[50],b[20];
    char p[50];
    printf("Enter your command\n");
    scanf("%s",com);
    char ap[50]="passwd";    
    int res=strcmp(ap,com);
    if(res==0)
    {
        //printf("entry");
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
    //printf("checkpoint");
    char checker[40];
    char inp[40];
    char udata[500];
    char cpass[50];
    char* uname;
    FILE* fp;
    struct upass db;
    char* token;
    int i=0;
    fp=fopen("passwd.txt","a+");
    //printf("checkpoint2");
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
    char buffer[1000];
    ts=fopen("shadow.txt","r");
    printf("checkpoint3");
    fgets(buffer,1000,ts);
    fclose(ts);
    printf("hmm");
    tok=strtok(buffer,":");
    s3.suser=tok;
    tok=strtok(NULL,":");
    s3.spwde=tok;
    fclose(ts);
    printf("checkpoint4");
    //char* decrypte=decrypt(db.epwd,s3.spwde);
    //printf("decrypte%s",decrypte);
    char decryptedMsg[100];
    char *msg;char *key;
    msg=db.epwd;
    key=s3.spwde;
    int msgLen = strlen(msg), keyLen = strlen(key),j;
    //printf("%d%d",msgLen,keyLen);
    //printf("checkpoint5");
    for(i = 0; i < msgLen; ++i)
    {
        decryptedMsg[i] = (((msg[i] - key[i]) + 26) % 26) + 'A';
        
    } 
    printf("\n%s\n",decryptedMsg);
    printf("checkpoint7");

    
     printf("Changing password for %s\n",uname);//get the user name from the file 
    //printf("\nCurrent password:");
    //cpass=getpass("Current password:");
    printf("Current password");
    scanf("%s",cpass);
    //printf("checkpoint8");
    if(strcmp(decryptedMsg,cpass)==0)
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
   printf("in chngpwd()");
}
/*char* decrypt(char* key,char* msg)
{
    char* decryptedMsg;
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;
    for(i = 0; i < msgLen; ++i)
    {
        decryptedMsg[i] = (((msg[i] - key[i]) + 26) % 26) + 'A';
    } 
 
    decryptedMsg[i] = '\0';
    char* dtype=typeof(decryptedMsg);
    printf("%s",dtype);
return(decryptedMsg);
 
}*/

    