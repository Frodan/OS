#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

int find(int* frames, int num, int frames_num){
    for (int i = 0; i < frames_num; i++){
        if (frames[i] == num){
            return i;
        }
    }
    return -1;
}

void move_right(unsigned char* age, int frames_num){
    for (int i = 0; i < frames_num; i++){
        age[i] = age[i] >> 1;
    }
}

void add(unsigned char* age, int num){
    age[num] = age[num] + 128;
}

int find_min_age(unsigned char* age, int frames_num){
    int ind = 0;
    unsigned int max = 256; // as 2**8, because max char has 255
    for (int i = 0; i < frames_num; i++){
        unsigned int tmp = (unsigned int)age[i];
        if (tmp < max){
            max = tmp;
            ind = i;
        }
    }
    return ind;

}

void debug(int* frames, unsigned char* age, int frames_num, int hit, int miss, int num){
    printf("----------------------------------\n");
    printf("Frames:\n");
    for (int i = 0; i < frames_num; i++){
        printf("%d ", frames[i]);
    }
    printf("\n");
    printf("----------------------------------\n");
    printf("Age:\n");
    for (int i = 0; i < frames_num; i++){
        printf("%d ", (unsigned int)age[i]);
    }
    printf("\n");
    printf("----------------------------------\n");
    printf("Hit:%d Miss:%d Cur num:%d\n\n\n", hit, miss, num);
}

int main(int argc, char* argv[]) {
    printf("Number of page frames:");
    int frames_num;
    scanf("%d", &frames_num);
    char filename[] = "input.txt";
    FILE *input;
    input = fopen(filename, "r");
    if (input == NULL){
        printf("No such file");
        return 0;
    }
    int number;
    int* frames = (int*)calloc(frames_num, sizeof(int));
    for (int i = 0; i < frames_num; i++){
        frames[i] = -1;
    }
    unsigned char* age = (unsigned char*)calloc(frames_num, sizeof(char));
    int hit = 0;
    int miss = 0;
    fscanf(input, "%d", &number);
    while (!feof(input)){
        move_right(age, frames_num);
        int free_space_ind = find(frames, -1, frames_num);
        int index = find(frames, number, frames_num);
        if (index != -1){
            hit++;
            add(age, index);

        }else{
            if (free_space_ind != -1){
                miss++;
                frames[free_space_ind] = number;
                age[free_space_ind] = 0;
                add(age, free_space_ind);
            }
            else{
                miss++;
                index = find_min_age(age, frames_num);
                frames[index] = number;
                age[index] = 0;
                add(age, index);
            }
        }
        debug(frames, age, frames_num, hit, miss, number);
        //sleep(2);
        fscanf(input, "%d", &number);
    }
    printf("Hit:%d, Miss:%d, Hit/miss:%f", hit, miss, (double)hit/miss);
    return 0;
}