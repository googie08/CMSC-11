#include <stdio.h>

int main() {
    int rows, cols;
    int arr[20][20];
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    for (int i=0; i<rows; i++) {
        printf("\n");
        for (int j=0; j<cols; j++) {
            printf("Enter element %d of Matrix %d: ", j+1, i+1);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n\n Addition of matrices:");
    for (int j=0; j<cols; j++) {
        printf("\n");
        for (int i=0; i<rows; i++) {
            printf("%d: ", arr[i][j]+arr[i][j]);
        }
    }
}

/*#include <stdio.h>

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

/*
#include <stdio.h>

// ===== Function Declarations (Prototypes) =====
void greet();
int add(int a, int b);
void printSum(int a, int b);
int getNumber(void);
void explainScope(void);
void changeValue(int x);
int factorial(int n);

// ===== Global Variable =====
int globalVar = 10;

// ===== main Function =====
int main() {
    printf("=== FUNCTION REVIEW PROGRAM ===\n\n");

    // 1. No parameters, no return
    greet();

    // 2. Has parameters and return
    int result = add(5, 7);
    printf("\nResult of add(5, 7): %d\n", result);

    // 3. Has parameters, no return
    printSum(3, 8);

    // 4. No parameters, has return
    int num = getNumber();
    printf("\nNumber returned from getNumber(): %d\n", num);

    // 5. Scope example
    explainScope();

    // 6. Call by value example
    int a = 5;
    printf("\nBefore calling changeValue(), a = %d\n", a);
    changeValue(a);
    printf("After calling changeValue(), a = %d (unchanged)\n", a);

    // 7. Recursion example
    int f = 5;
    printf("\nFactorial of %d is %d\n", f, factorial(f));

    printf("\n=== END OF REVIEW ===\n");
    return 0;
}

// ===== Function Definitions =====

// 1. No parameters, no return
void greet(void) {
    printf("Hello! This function has no parameters and no return value.\n");
}

// 2. Has parameters and return
int add(int a, int b) {
    int sum = a + b;
    return sum;
}

// 3. Has parameters, no return
void printSum(int a, int b) {
    printf("\nSum of %d and %d is: %d\n", a, b, a + b);
}

// 4. No parameters, has return
int getNumber(void) {
    return 42;
}

// 5. Scope example
void explainScope(void) {
    int localVar = 20;
    printf("\nInside explainScope():\n");
    printf("Local variable = %d\n", localVar);
    printf("Global variable = %d\n", globalVar);
}

// 6. Call by value example
void changeValue(int x) {
    x = 100;
    printf("Inside changeValue(), x = %d\n", x);
}

// 7. Recursive function example
int factorial(int n) {
    if (n == 0)
        return 1;  // base case
    else
        return n * factorial(n - 1);  // recursive case
}
*/

/*
#include <stdio.h>

float computeAverage(int a, int b, int c);
char getRemarks(float average);
void displayResult(float avg, char grade);

int main() {
    int a, b, c;
    printf("Enter three quiz scores: ");
    scanf("%d %d %d", &a, &b, &c);

    float average = computeAverage(a, b, c);
    char grade = getRemarks(average);
    displayResult(average, grade);
}

float computeAverage(int a, int b, int c) {
    return (a+b+c) / 3;
}

char getRemarks(float average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else if (average < 60) return 'F';
}

void displayResult(float avg, char grade) {
    printf("\nAverage score: %.2f \nGrade: %c\n", avg, grade);
}
*/

/*
    #include <stdio.h>

int summation(int);

int main() {
    int n, sum;
    scanf("%d", &n);
    sum = summation(n);
    printf("%d", sum);
    return 0;
}

int summation(int n) {
    if (n==0) return n;
    return n+summation(n-1);
}
*/

/*
    #include <stdio.h>

int countDigits(int n);

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int digits = countDigits(num);
    printf("Number of digits = %d\n", digits);
}

int countDigits(int n) {
    if (n==0) return n;
    return 1 + countDigits(n/10);
}
*/

/*
#include <stdio.h>

// 1. Function to display array elements
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 2. Function to compute sum of array elements
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// 3. Function to find maximum element
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// 4. Function to find minimum element
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

// 5. Function to reverse an array (in-place)
void reverseArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

// 6. Function to demonstrate 2D array (matrix input and output)
void display2DArray(int rows, int cols) {
    int matrix[10][10];
    printf("\nEnter elements for a %dx%d matrix:\n", rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[100];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    displayArray(arr, size);

    printf("Sum of array elements = %d\n", sumArray(arr, size));
    printf("Maximum element = %d\n", findMax(arr, size));
    printf("Minimum element = %d\n", findMin(arr, size));

    reverseArray(arr, size);
    printf("Array after reversing:\n");
    displayArray(arr, size);

    int rows, cols;
    printf("\nNow let's try a 2D array (matrix)\n");
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    display2DArray(rows, cols);

    return 0;
}

*/

/*
#include <stdio.h>

void displayArray(int arr[], int size);
int sumArray(int arr[], int size);
float averageArray(int arr[], int size);
int countEven(int arr[], int size);
int countOdd(int arr[], int size);
int findMax(int arr[], int size);
int findMin(int arr[], int size);

int main() {
    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int arr[100];
    for (int i=0; i<size; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    displayArray(arr, size);
    printf("\nSum = %d", sumArray(arr, size));
    printf("\nAverage = %.2f", averageArray(arr, size));
    printf("\nEven numbers = %d", countEven(arr, size));
    printf("\nOdd numbers = %d", countOdd(arr, size));
    printf("\nMaximum = %d", findMax(arr, size));
    printf("\nMinimum = %d\n", findMin(arr, size));

    return 0;
}

void displayArray(int arr[], int size){
    printf("\nArray elements: ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
}

int sumArray(int arr[], int size) {
    int sum=0;
    for (int i=0; i<size; i++) {
        sum = sum+arr[i];
    }
    return sum;
}

float averageArray(int arr[], int size) {
    float sum=0;
    for (int i=0; i<size; i++) {
        sum = sum+arr[i];
    }
    return (sum/size);
}

int countEven(int arr[], int size) {
    int count=0;
    for (int i=0; i<size; i++) {
        if(arr[i]%2==0) {
            count++;
        }
    }
    return count;
}

int countOdd(int arr[], int size) {
    int count=0;
    for (int i=0; i<size; i++) {
        if(arr[i]%2==1) {
            count++;
        }
    }
    return count;
}
int findMax(int arr[], int size) {
    int max=arr[0];
    for (int i=1; i<size; i++) {
        if(arr[i]>max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int arr[], int size) {
    int min=arr[0];
    for (int i=1; i<size; i++) {
        if(arr[i]<min) {
            min = arr[i];
        }
    }
    return min;
}

*/