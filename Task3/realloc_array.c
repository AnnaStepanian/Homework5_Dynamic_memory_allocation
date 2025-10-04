#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    
    array = (int*)malloc(10 * sizeof(int));
    
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter 10 integers: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
    }
    
    array = (int*)realloc(array, 5 * sizeof(int));
    
    if (array == NULL) {
        printf("Error: Memory reallocation failed.\n");
        return 1;
    }
    
    printf("Array after resizing: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    free(array);
    
    return 0;
}
