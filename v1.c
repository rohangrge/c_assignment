#include<stdio.h>
#include<string.h>
void cmd();
void chcmd();
int main(void)
{
    cmd();
}



void cmd()
{   
    char com[50];
    printf("Enter your command\n");
    scanf("%s",com);
    char a[50]="passwd";
    
    if(strcmp(a,com)==0)
    {
        printf("You have entered the right command");
    }
    else
    {
      cmd();
    }
}

    