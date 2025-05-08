#include<stdio.h>
#include "utils.h"
#include<stdlib.h>
#include<string.h>
#include "bytes.h"
#include<stdint.h>
int main(int argc, char *argv[]) {
    if(argc == 1) {
        printf("error, need a file name");
        return 1;
    }        
    else if(strcmp("-v", argv[1]) == 0) {
        printf("patricus utils, version %s", version);
        return 0;
    }       
    else if(argc == 2) {
        FILE *f = fopen(argv[1], "rb");
        if(f == NULL) {
            perror("error while loading the file");
            return 1;
        }
        fseek(f, 0, SEEK_END);
        size_t *a = malloc(sizeof(size_t));
        *a = ftell(f);
        fclose(f);

        // Allocate memory for the converted size string and assign
        char *converted = malloc(50);
        if (converted != NULL) {
            snprintf(converted, 50, "%s", format_bytes(*a));
}
        
printf("opened only file and it's %s", converted);
        
        free(a);
        return 0;
    }
    else {
        FILE *f = fopen(argv[1], "rb");
        if(f == NULL) {
            perror("error while loading the first file");
            return 1;
        }
        fseek(f, 0, SEEK_END);
        int64_t *a = malloc(sizeof(int64_t));
        *a = ftell(f);
        fclose(f);
        char *converteda = malloc(50);
        if (converteda != NULL) {
            snprintf(converteda, 50, "%s", format_bytes(*a));
}
f = fopen(argv[2], "rb");
if(f == NULL) {
perror("error while loading the second file");
return 1;
        }
fseek(f, 0, SEEK_END);
size_t *b = malloc(sizeof(size_t));
*b = ftell(f);
fclose(f);
        char *convertedb = malloc(50);
        if (convertedb != NULL) {
            snprintf(convertedb, 50, "%s", format_bytes(*b));
        }
        if(*a > *b) {
            printf("first file is bigger, %s, second is %s", converteda, convertedb);
        }
        else if(*b > *a) {
            printf("second file is bigger, %s the first is %s", convertedb, converteda);
        }
        else {
            printf("they're equal, %s", converteda);
        }
        free(a);
        free(b);
        free(converteda);
        free(convertedb);
    }
}