#include<stdio.h>
#include<string.h>
#include<pwd.h>
#include<unistd.h>
void cmd();
void chcmd();
int main(void)
{
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
        //printf("You have entered the right command");
        printf("working2\n");
        typeof(getpass(""));
        strncpy(p,getpass("Password:"),80);
        printf("working1");

        
    }
    else
    {
      cmd();
    }
    printf("working");
    printf("%s",p);
}


    