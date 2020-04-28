#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define ISDIR 4 //d_type for directory is 4



int find(const char *WTL){
    char temp[1];
    DIR* dot; struct dirent* nextEnt; char lastSlash[] = "/";
    DIR* dot1; char filenamer[100] = "./"; char* dirName; char *nextPath;
    if(WTL == NULL){ //if no directory specified, check current dir
        dot = opendir("."); //open buffer at current directory  
    }
    else{
        dot = opendir(WTL); //open buffer at specified directory
    }
    if(dot == NULL){ //could not open dir
        printf("Cannot open"); //indicated directory could not be opened
    }
    nextEnt = readdir(dot); nextEnt = readdir(dot); //skips .. and . directories
    while ((nextEnt = readdir(dot)) != NULL){ //check next address
        if(nextEnt->d_type == ISDIR){ //if it is a directory check it
            dirName = nextEnt->d_name;
            nextPath = strcat(filenamer, dirName); 
            nextPath = strcat(nextPath, lastSlash);
            printf("inside");
            printf("\n %s", nextPath);
            scanf("%s", temp);
            
            //find(nextPath);
        }
        printf("\n %s ", nextEnt->d_name); //print entry name
    }

    return 0;
}

int main(){
    char str[10]; char temp[1];
    find(NULL);
    printf("passed first");
    printf("\n %s", temp);
    scanf("%s", str);
    find(temp);
    printf("passed both");
    scanf("%s", str);
    return 0;
}
