#include <stdio.h>

void readArray(int arr[], int n);
void printArray(int arr[], int n);
void recursiveSort(int arr[], int n, int index);
void swap(int *a, int *b);

int main() {
    int n, arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    readArray(arr, n);

    printf("\nOriginal array: ");
    printArray(arr, n);

    recursiveSort(arr, n, 0);

    printf("\nSorted array (ascending): ");
    printArray(arr, n);

    return 0;
}

void readArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive selection sort
void recursiveSort(int arr[], int n, int index) {
    // Base case: done if last element reached
    if (index == n - 1)
        return;

    int minIndex = index;
    for (int j = index + 1; j < n; j++) {
        if (arr[j] < arr[minIndex])
            minIndex = j;
    }

    // Swap smallest element with current position
    if (minIndex != index)
        swap(&arr[minIndex], &arr[index]);

    // Recurse on the remaining unsorted portion
    recursiveSort(arr, n, index + 1);
}


/*
#include <stdio.h>

// Find the maximum number
void readArray(int arr[], int index, int n);
int findMax(int arr[], int n);
void printArray(int arr[], int index, int n);

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    readArray(arr, 0, n);

    printf("\nYou entered: ");
    printArray(arr, 0, n);
    printf("\n");

    int maxValue = findMax(arr, n);
    printf("Maximum = %d\n", maxValue);

    return 0;
}

void readArray(int arr[], int index, int n) {
    if (index == n) return;
    scanf("%d", &arr[index]);
    readArray(arr, index + 1, n);
}

void printArray(int arr[], int index, int n) {
    if (index == n) return;
    printf("%d ", arr[index]);
    printArray(arr, index + 1, n);
}

int findMax(int arr[], int n) {
    if (n == 1) return arr[0];
    int maxRest = findMax(arr, n - 1);
    if (arr[n - 1] > maxRest) return arr[n - 1];
    else return maxRest;
}










# include <stdio.h>

// Count even numbers

void get(int arr[], int i, int n);
int even(int arr[], int i, int n);

int main() {
    int n, out;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    get(arr, 0, n);
    out = even(arr, 0, n);
    printf("\nNumber of even elements = %d", out);
}

void get(int arr[], int i, int n) {
    if (i == n) return;
    printf("Enter number %d: ", i+1);
    scanf("%d", &arr[i]);
    get(arr, i+1, n);
}

int even(int arr[], int i, int n) {
    if (i == n) return 0;

    int countRest = even(arr, i+1, n);

    if (arr[i] == 0) return countRest;
    else if ((arr[i]%2) == 0) return countRest+1;
    else return countRest;
}














#include <stdio.h>

// Function prototypes
void readMatrix(int matrix[10][10], int rows, int cols);
void printMatrix(int matrix[10][10], int rows, int cols);
void sumRows(int matrix[10][10], int rows, int cols);
void sumCols(int matrix[10][10], int rows, int cols);

int main() {
    int rows, cols;
    int matrix[10][10]; // limit size to 10x10 for simplicity

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("\nEnter elements of the matrix:\n");
    readMatrix(matrix, rows, cols);

    printf("\nMatrix entered:\n");
    printMatrix(matrix, rows, cols);

    printf("\nSum of each row:\n");
    sumRows(matrix, rows, cols);

    printf("\nSum of each column:\n");
    sumCols(matrix, rows, cols);

    return 0;
}

// 🧩 Reads elements into the matrix
void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// 🧩 Displays the matrix
void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

// 🧩 Computes the sum of each row
void sumRows(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        printf("Row %d = %d\n", i + 1, sum);
    }
}

// 🧩 Computes the sum of each column
void sumCols(int matrix[10][10], int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        printf("Column %d = %d\n", j + 1, sum);
    }
}














#include <stdio.h>

// Function prototypes
void readMatrix(int matrix[10][10], int rows, int cols);
void printMatrix(int matrix[10][10], int rows, int cols);
void transposeMatrix(int matrix[10][10], int rows, int cols);

int main() {
    int rows, cols;
    int matrix[10][10], transposed[10][10];

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("\nEnter elements of the matrix:\n");
    readMatrix(matrix, rows, cols);

    printf("\nOriginal matrix:\n");
    printMatrix(matrix, rows, cols);

    printf("\nTransposed matrix:\n");
    transposeMatrix(matrix, rows, cols);

    return 0;
}

// Reads a matrix from input
void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Prints a matrix
void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

// Computes the transpose of a matrix
void transposeMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
           printf("%4d", matrix[j][i]);
        }
        printf("\n");
    }
}

*/
