#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *array;
    int sum = 0;
    double average;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Error: Number of elements must be positive.\n");
        return 1;
    }
    
    array = (int*)calloc(n, sizeof(int));
    
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    
    printf("Array after calloc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("Updated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
        sum += array[i];
    }
    printf("\n");
    
    average = (double)sum / n;
    printf("Average of the array: %.1f\n", average);
    
    free(array);
    
    return 0;
}
