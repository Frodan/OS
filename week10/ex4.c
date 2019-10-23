#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int find(unsigned long a, unsigned long *array, int len){
    for (int i = 0; i < len; i++){
        if (array[i] == a){
            return 1;
        }
    }
    return 0;
}


int main() {
    DIR *tmp, *tmp1;
    struct dirent *entry, *entry1;
    struct stat fileStat;
    char path[5] = "tmp/";
    char filepath[256];
    unsigned long *history = calloc(1024, sizeof(unsigned long));
    int index = 0;

    tmp = opendir("tmp");
    if (tmp == NULL){
        printf("No such folder.");
        return 0;
    }

    while ((entry = readdir(tmp)) != NULL){
        sprintf(filepath, "%s%s", path, entry->d_name);
        stat(filepath, &fileStat);

        if (fileStat.st_nlink >= 2 && !find(fileStat.st_ino, history, 1024)){
            unsigned long inum = fileStat.st_ino;
            tmp1 = opendir("tmp");
            while ((entry1 = readdir(tmp1)) != NULL){
                sprintf(filepath, "%s%s", path, entry1->d_name);
                stat(filepath, &fileStat);
                if (inum == fileStat.st_ino) {
                    printf("%s ", entry1->d_name);
                }
            }
            printf("\n");
            history[index] = inum;
            index++;
        }
    }
    return 0;
}