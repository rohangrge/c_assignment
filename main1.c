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
int main(void)
{
    cmd();
}