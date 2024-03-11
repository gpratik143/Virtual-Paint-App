#include <stdio.h>
#include <stdlib.h>
void insert_element(int *array, int *size, int element, int position) {
    if (position < 1 || position > *size + 1) {
        printf("Error: Position is out of bound\n");
        return;
    }
    (*size)++;
    array = realloc(array, (*size) * sizeof(int));
    for (int i = *size - 1; i > position - 1; i--) {
        array[i] = array[i - 1];
    }
    array[position - 1] = element;
    printf("Array after insertion:\n");
    for (int i = 0; i < *size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    int element, position;
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    printf("Enter the position where the element should be inserted: ");
    scanf("%d", &position);
    insert_element(array, &size, element, position);
    free(array);
    return 0;
}
