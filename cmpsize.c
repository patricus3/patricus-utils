//cmpsize
#include<stdio.h>
#include "utils.h"
#include<stdlib.h>
#include<string.h>
#include "bytes.h"
int main(int argc,char *argv[]){
    if(argc==1){
        printf("error");
return 1;
    }        
else if( strcmp("-v",argv[1])==0){
        printf("patricus utils, version %s",version);
        return 0;
        }       
        else if(argc==2){
        FILE *f=fopen(argv[1],"RB");
if(f==NULL){
fprintf(stderr,"error while loading the file");
return 1;
}
        fseek(f,0,SEEK_END);
        size_t *a=malloc(sizeof(size_t));
        *a=ftell(f);
char* converted=format_bytes(*a);
        printf("opened only file and it's %s",converted);
        return 0;
}
else{
FILE *f=fopen(argv[1],"RB");
if(f==NULL){
    fprintf(stderr,"error while loading the file");
    return 1;
    }    
fseek(f,0,SEEK_END);
size_t *a=malloc(sizeof(size_t));
*a=ftell(f);
char* *converteda=malloc(50);
*converteda=format_bytes(*a);
fclose(f);
f=fopen(argv[2],"RB");
if(f==NULL){
    fprintf(stderr,"error while loading the file");
    return 1;
    }    
fseek(f,0,SEEK_END);
size_t *b=malloc(sizeof(size_t));
*b=ftell(f);
char* *convertedb=malloc(50);
*convertedb=format_bytes(*b);
fclose(f);
if(*a>*b){
printf("first file is bigger, %s, second is %s",*converteda,*convertedb);
}
else if(*b>*a){
printf("second file is bigger, %s the first is %s",*convertedb,*converteda);
}
else{
printf("they'ree equal, %lld",*a);
}
free(a);free(b);free(converteda);free(convertedb);
//we free the memory so we don't leak it by accident, + we get more control on when it gets freed, it's 16 bytes after all, not much but always something.
}}