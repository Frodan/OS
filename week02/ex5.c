#include <stdio.h>
#include <stdlib.h>

void print_n_chars(int n, char c){
    for (int i = 0; i < n; i++){
        printf("%c", c);
    }
}

void print_pyramid(int height){
    int bottom_width, width;
    bottom_width = 2 * height - 1;
    height += 1;
    for (int i = 0; i < height; i++){
        width = i * 2 - 1;
        int num_of_spaces = (bottom_width - width) / 2;
        print_n_chars(num_of_spaces, ' ');
        print_n_chars(width, '*');
        print_n_chars(num_of_spaces, ' ');
        printf("\n");
    }
}

void print_triangle(int height){
    height += 1;
    for (int i = 0; i < height; i++){
        print_n_chars(i, '*');
        printf("\n");
    }
}

void print_rectangle(int height){
    for (int i = 0; i < height; i++){
        print_n_chars(height, '*');
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    int height, figure;
    height = atoi(argv[1]);
    printf("Choose figure:\n1)Triangle\n2)Pyramid\n3)Rectangle\n");
    char line[100];
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &figure);
    if (figure == 1){
        print_triangle(height);
    }else if (figure == 2){
        print_pyramid(height);
    }
    else{
        print_rectangle(height);
    }
}