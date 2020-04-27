#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define ISDIR 4 //d_type for directory is 4



char * trimmer(char *array){
    char * temp; int i = 0; temp = array;
    for(i = 0; array[i] != NULL; i++);
    free(array);
    array = (char*)malloc((i+1)*sizeof(char));
    for(int j = 0; j < i;j++){
        array[j] = temp[j];
    }
}


int find(const char *WTL){
    DIR* dot; struct dirent* nextdir; char lastSlash[1] = "/";
    DIR* dot1; char filenamer[100] = "/"; char* dirName; char *nexter;
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
    nextdir = readdir(dot);
    nextdir = readdir(dot); 
    while ((nextdir = readdir(dot)) != NULL){ //check next address
        if(nextdir->d_type == ISDIR){ //if it is a directory check it
            nexter = (char*)malloc((strlen(nextdir->d_name))*sizeof(char));
            dirName = nextdir->d_name;
            nexter = strcat(filenamer, dirName); 
            nexter = strcat(nexter, lastSlash);
            printf("\n %s", nexter);
            //find(nexter);
            //find(strcat(nextdir->d_name, temp));//call find at subdirectory
        }
        printf("\n %s ", nextdir->d_name); //print entry name
    }
    return 0;
}

int main(){
    char str1[20] = "hello";
    trimmer(str1);
    printf("%s", str1);
    find(NULL);
    scanf("%s", str1);
    return 0;
}
