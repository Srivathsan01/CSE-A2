#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/utsname.h>
#include<signal.h>
#include<sys/wait.h>    
int systemcommand(char *syscom,int flag)
{
    char *argu[] = {syscom,NULL};
    if(flag==1)         // & was given
    {
        int status;
        int ind = fork();
        if(ind==0)
        {
            setpgid(0,0);       
            execvp(syscom,argu);            //Child execvp(command)
        }
        else if(ind > 0)
        {
            waitpid(-1,&status, WNOHANG | WUNTRACED);
            return ind;                                             //return process id to shell
            // printf("Child pushed to background\n");
        }
    }
    else
    {
        int ind = fork();
        if(ind ==0)
        {
            // printf("I am child going into %s\n",syscom);
            execvp(syscom,argu);
        }
        else
        {
            // printf("Parent waiting\n");
            wait(NULL);
        }
        
    }
    

}