#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>




#define ISDIR 4 //d_type for directory is 4



int find(const char *WTL){
    DIR* dot; struct dirent* nextdir;
    DIR* dot1;
    if(WTL == NULL){ //if no directory specified, check current dir
        dot = opendir("."); //open buffer at current directory  
    }
    else{
        dot = opendir(WTL); //open buffer at specified directory
    }
    if(dot == NULL){ //could not open dir
        printf("Cannot open"); //indicated directory could not be opened
    }
    //nextdir = readdir(dot + 1);
    // nextdir = readdir(dot);
    // nextdir = readdir(dot);
    while ((nextdir = readdir(dot)) != NULL){ //check next address
        if(nextdir->d_type == ISDIR){ //if it is a directory check it
            printf("hello");
            dot1 = opendir(nextdir->d_name); //open buffer at directory
            //find(nextdir->d_name);//call find at subdirectory
        }
        printf("%s ", nextdir->d_name); //print entry name
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
