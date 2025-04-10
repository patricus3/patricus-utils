#include"utils.h"
#include <stdio.h>
#include <stdlib.h>
#include<sys/stat.h>
#include<string.h>
int main(int argc,char *argv[])
{
#ifdef beta
ShowCrashReports();
#endif
    if(argc==1) {
        char *noargs=malloc(1);
        int bytes;
//I'm not an idiot and wrote dynalloc just for dynamically allocating memory, thanks
//making a new variable  to store value returned by fread, to stop when needed.
        while((bytes=(fread(noargs,1,1,stdin)==1))) {
//read from stdin, to noargs, saving return code to see if fread had read any bytes, if yes, we'll get 1 if not, then something else we don't need to care about
if(!feof(stdin)){
printf("%c",*noargs);
}
        }
free(noargs);
        return 0;
    }
    if(strcmp(argv[1],"-v")==0)
     {
        printf("patricus utils, version %s",version);
        return 0;
     }
for(int meowing=1;meowing<argc;meowing++){
    FILE *f=fopen(argv[meowing],"r");
//opening a file from cli arguments
    struct stat filecheck;
//here we see if the user is an idiot and the file doesn't exist, we won't crash if a file is dir so
    if(stat(argv[meowing],&filecheck)==-1) {
        printf("file not found.");
        return 1;
    }
    //I actually wrote a check for dirs.
    if((filecheck.st_mode&S_IFDIR)==S_IFDIR)
    {
        printf("it is a directory");
    }
    int size=ftell(f);
    char *meow=malloc(1);
    fseek(f,0,SEEK_SET);
    int readBytes;
while ((readBytes = fread(meow, 1, 1, f ))== 1) {
printf("%c",*meow);
}
fclose(f);
free(meow);
}}