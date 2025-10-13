#include <stdio.h>

voidarrayRotate(int*, int, int, int);



int main() {
    //int arr[2][3][2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int [3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int rows = 2;
    int cols = 3;
    // int height = 2;

    int *ptr = arr;

    /*
    int i = 1;
    int j = 1;

    for(i=0; i<rows*cols*height; i++) {
        printf("%d", *(ptr+i));
    }
    */

    while(1){
        arrayRotate(ptr, rows, cols);
    }

    return 0;
}

void arrayRotate(int *ptr, int rows, int cols, int rotations) {
    for(int i=0; rot<rotations; rot++) {
        int last = *(pt+(rows*cols)-1);
        for (int i=(rows*cols)-1; i>0; i--) {
            *(ptr+i) = *(ptr+i-1);
        }
        *ptr = last;
        arrayPrinter(ptr, rows, cols);
    }
}

void arrayPrinter(int *ptr, int rows, int cols, int rotations) {
    for(int i=0; i<rows*cols; i++) {
        if (i%(rows) == 0)
        printf("%d", *(arr+i));
    }
}

