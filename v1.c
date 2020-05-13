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
    char *suser;
    char *spwde;
    char *lpchng;
    char *smin;
    char *smax;
    char *swarn;
    char *inact;
    char *exp;
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
    char *cpass;
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
    //printf("%s\n",token);
    db.user=token;
    token=strtok(NULL,":");
    db.epwd=token;
    fclose(fp);
    struct spwd s3;
    char buffer[1000];
    FILE* ts;
    char* tok;
    int key;
    int f;
    ts=fopen("shadow.txt","r");
    //printf("hmm");
    fgets(buffer,1000,ts);
    
    tok=strtok(buffer,":");
    s3.suser=tok;
    tok=strtok(NULL,":");
    s3.spwde=tok;
    key=atoi(db.epwd);

    

    //printf("jmmm");
      
//decrypt
      for(f = 0; (f< 100 && s3.spwde[f] != '\0'); f++)
      {
        s3.spwde[f] = s3.spwde[f] - key;
    } 
    //printf("\n%s\n",s3.spwde);
    

    //printf("checking");
     printf("Changing password for %s.\n",db.user);//get the user name from the file 
    //printf("\nCurrent password:");
    cpass=getpass("Current password:");
    //printf("Current password");
    //scanf("%s",cpass);
    //printf("checkpoint8");
    if(strcmp(s3.spwde,cpass)==0)
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
   char* npwd;
   char temp[1000];
   int f;
   char* to;
   npwd=getpass("New password:");
   FILE* fm;
   struct spwd s4;
   fm=fopen("shadow.txt","r+");
   fgets(temp,1000,fm);
   to=strtok(temp,":");
   s4.suser=to;
   to=strtok(NULL,":");
   s4.spwde=to;
   to=strtok(NULL,":");
   s4.lpchng=to;
   to=strtok(NULL,":");
   s4.smin=to;
   to=strtok(NULL,":");
   s4.smax=to;
   to=strtok(NULL,":");
   s4.swarn=to;
   to=strtok(NULL,":");
   s4.inact=to;
   to=strtok(NULL,":");
   s4.exp=to;
   s4.spwde=npwd;
   for(f = 0; (f< 100 && s4.spwde[f] != '\0'); f++)
      {
        s4.spwde[f] = s4.spwde[f] + 3;
    } 
    frewind(fp);
    fwrite(&s4,sizeof(struct spwd),8,fm);
    printf("\nPassword changed succesfully");

   
   
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

    