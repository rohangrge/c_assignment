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
void cmd();
void chcmd();
void chkpwd();
void chngpwd();
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
    
     printf("Changing password for %s\n",uname);//get the user name from the file 
    //printf("\nCurrent password:");
    cpass=getpass("Current password:");
    if(strcmp(checker,inp)==0)
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

    