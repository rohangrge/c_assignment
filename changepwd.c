#include<stdio.h>
#include<string.h>
//#include<pwd.h>
//#include<system.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
//#include<conio.h>
#include "user.h"
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
void chngpwd(char *tpwd,int count)
{
   char npwd[100];
   char *temp;
   int f;
   char* to;
  const char* get=getenv("PFILE");
    //const char* temp1= getenv("etc/passwd");    
    // char* temp2=getenv("etc/shadow");
    char temp1[100],temp2[100];
    strcpy(temp1,get);
    strcpy(temp2,get);
    strcat(temp1,"/passwd.txt");
    strcat(temp2,"/shadow.txt");
   char write[100]="";
   char npwd1[100];
  // npwd=getpass("New password:");
   printf("New password:");
   scanf("%s",npwd);
   printf("Retype new password:");
   scanf("%s",npwd1);
   if(strcmp(npwd,npwd1)!=0)
   {
       printf("\nSorry, passwords do not match.");
       printf("\npasswd: Authentication token manipulation error");
       printf("\npasswd: password unchanged\n");
       main();
   }
   if(strcmp(npwd,npwd1)==0)
   {
       if(strcmp(npwd,tpwd)==0)
       {
           printf("Password unchanged\n");
           
           count++;
           if(count==3)
           {
               printf("passwd: Authentication token manipulation error");
               printf("\npasswd: password unchanged\n");
               main();
           }
           //printf("%d",count);
           chngpwd(tpwd,count);
           
       }
   }
   FILE* fm;
   struct spwd s4;
   fm=fopen(temp2,"r");
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
   fclose(fm);
   for(f = 0; (f< 100 && s4.spwde[f] != '\0'); f++)
      {
        s4.spwde[f] = s4.spwde[f] + 3;
    } 
    rewind(fm);
    strcat(write,s4.suser);
    strcat(write,":");
    strcat(write,s4.spwde);
    strcat(write,":");
    strcat(write,s4.lpchng);
    strcat(write,":");
    strcat(write,s4.smin);
    strcat(write,":");
    strcat(write,s4.smax);
    strcat(write,":");
    strcat(write,s4.swarn);
    strcat(write,":");
    strcat(write,s4.inact);
    strcat(write,":");
    strcat(write,s4.inact);
    
    

    fm=fopen(temp2,"w");
    char ter[100];
    fwrite(write,sizeof(s4),1,fm);
    fclose(fm);
 
    printf("\nPassword changed succesfully\n");
    exit(1);
   
   
}