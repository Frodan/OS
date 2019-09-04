#include <stdio.h>
#include <stdlib.h>

void print_n_chars(int n, char c){
    for (int i = 0; i < n; i++){
        printf("%c", c);
    }
}

int main(int argc, char* argv[]) {
    int height, bottom_width, width;
    height = atoi(argv[1]);
    height += 1;
    bottom_width = 2 * height - 1;
    for (int i = 0; i < height; i++){
        width = i * 2 - 1;
        int num_of_spaces = (bottom_width - width) / 2;
        print_n_chars(num_of_spaces, ' ');
        print_n_chars(width, '*');
        print_n_chars(num_of_spaces, ' ');
        printf("\n");
    }
    return 0;

}
