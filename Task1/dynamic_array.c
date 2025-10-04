#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *array;
    int sum = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Error: Number of elements must be positive.\n");
        return 1;
    }
    
    array = (int*)malloc(n * sizeof(int));
    
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    
    printf("Sum of the array: %d\n", sum);
    
    free(array);
    
    return 0;
}
