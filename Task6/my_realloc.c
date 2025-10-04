#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* my_realloc(void* ptr, size_t old_size, size_t new_size) {
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    
    if (ptr == NULL) {
        return malloc(new_size);
    }
    
    void* new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        return NULL;
    }
    
    size_t copy_size = (old_size < new_size) ? old_size : new_size;
    memcpy(new_ptr, ptr, copy_size);
    free(ptr);
    
    return new_ptr;
}

int main() {
    int *arr = NULL;
    int n;
    
    printf("Enter array size: ");
    scanf("%d", &n);
    
    arr = (int*)my_realloc(NULL, 0, n * sizeof(int));
    
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int new_n;
    printf("Enter new size: ");
    scanf("%d", &new_n);
    
    arr = (int*)my_realloc(arr, n * sizeof(int), new_n * sizeof(int));
    
    if (new_n > 0) {
        printf("New array: ");
        for (int i = 0; i < new_n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    my_realloc(arr, new_n * sizeof(int), 0);
    
    return 0;
}
