#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char **strings;
    int initial_count = 3;
    int additional_count = 2;
    int total_count = initial_count + additional_count;
    
    strings = (char**)malloc(initial_count * sizeof(char*));
    
    if (strings == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    
    for (int i = 0; i < initial_count; i++) {
        strings[i] = (char*)malloc(51 * sizeof(char));
        if (strings[i] == NULL) {
            printf("Error: Memory allocation failed for string %d.\n", i);
            for (int j = 0; j < i; j++) {
                free(strings[j]);
            }
            free(strings);
            return 1;
        }
    }
    
    printf("Enter 3 strings: ");
    for (int i = 0; i < initial_count; i++) {
        scanf("%s", strings[i]);
    }
    
    for (int i = 0; i < initial_count; i++) {
        printf("%s ", strings[i]);
    }
    printf("\n");
    
    strings = (char**)realloc(strings, total_count * sizeof(char*));
    
    if (strings == NULL) {
        printf("Error: Memory reallocation failed.\n");
        for (int i = 0; i < initial_count; i++) {
            free(strings[i]);
        }
        return 1;
    }
    
    for (int i = initial_count; i < total_count; i++) {
        strings[i] = (char*)malloc(51 * sizeof(char));
        if (strings[i] == NULL) {
            printf("Error: Memory allocation failed for string %d.\n", i);
            for (int j = 0; j < i; j++) {
                free(strings[j]);
            }
            free(strings);
            return 1;
        }
    }
    
    printf("Enter 2 more strings: ");
    for (int i = initial_count; i < total_count; i++) {
        scanf("%s", strings[i]);
    }
    
    printf("All strings: ");
    for (int i = 0; i < total_count; i++) {
        printf("%s ", strings[i]);
    }
    printf("\n");
    
    for (int i = 0; i < total_count; i++) {
        free(strings[i]);
    }
    free(strings);
    
    return 0;
}
