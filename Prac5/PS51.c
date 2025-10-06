#include<stdio.h>

int main(){
    int numbers[10];
    int SIZE = 0, i = 0, count = 0, valid = 0;

    printf("How many numbers do you want to store in the array(1-10)? ");
    scanf("%d", &SIZE);
    printf("\n");

    if(SIZE <= 0){
        printf("Invalid Input\n");
        return 0;
    }
    else if(SIZE > 10){
        printf("Invalid Input\n");
        return 0;
    }

    while(i < SIZE){
        printf("Enter number[%d]: ", i+1);
        scanf("%d", &numbers[i]);
        i++;
    }

    for(i = 0; i < SIZE; i++){
        if(numbers[i] == 3){
            count++;
            if(i + 1 < SIZE){
                if(numbers[i + 1] == 3){
                    valid++;
                    break;
                }
            }
        }
    }

    if(count == 3){
        if(valid == 0){
            printf("\nTRUE\n");
        }
        else {
            printf("\nFALSE\n");
        }
    }
    else {
        printf("\nFALSE\n");
    }

    return 0;
}
