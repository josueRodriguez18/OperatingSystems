#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>




#define ISDIR 4



int find(const char *WTL){
    DIR* dot; struct dirent* nextdir;
    DIR* dot1;
    if(WTL == NULL){
        dot = opendir(".");   
    }
    else{
        dot = opendir(WTL);
    }
    if(dot == NULL){
        printf("Cannot open");
    }
    nextdir = readdir(dot + 1);
    while ((nextdir = readdir(dot)) != NULL){
        if(nextdir->d_type == ISDIR){
            printf("hello");
            dot1 = opendir(nextdir->d_name + '/');
        }
        printf("%s ", nextdir->d_name);
        printf("%u \n", nextdir->d_type); //directory is 4
    }
    return 0;
}

int main(){
    char str1[20];

    find(NULL);
    scanf("%s", str1);
    return 0;
}
