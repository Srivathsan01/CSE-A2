#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/utsname.h>

void addtohistory(char *newcommand)
{
    char *com=(char *)malloc(100*sizeof(char));
    com = newcommand;
    char str[100];
    int numcommands = 0;
    FILE* fptr;
    FILE* temp;
    if((fptr=fopen("/home/srivathsan/Desktop/CSE/A2/history.txt", "a+")) == NULL)
    {
        perror("history.txt");
    }
    if((temp = fopen("/home/srivathsan/Desktop/CSE/A2/temp.txt", "w")) == NULL)
    {
        perror("temp.txt");
    }
    while( fgets(str,100, fptr) != NULL)
    {
        numcommands++;
    }    
    if(numcommands == 20)
    {
        char dump[100];
        fgets(dump,100, fptr);          //first line is garbage
        while( fgets(str,100, fptr) != NULL)
        {
            fputs(str,temp);
        }
        fputs(newcommand,temp);             //Last line the new command is added
    }
    else if(numcommands < 20)
    {
        fputs(newcommand,fptr);
    }
    
}
void readhistory()
{
    FILE* fptr;
    fptr=fopen("/home/srivathsan/Desktop/CSE/A2/history.txt", "r");
    if(fptr == NULL)
    {
        perror("fptr");
        return;
    }
    char str[100];
    while( fgets(str,100, fptr) != NULL)
    {
        printf("%s\n",str);
    }    
    
}