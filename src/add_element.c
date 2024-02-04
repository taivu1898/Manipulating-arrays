#include "io_array.h"

int *add_element(int *, int *, int, int);

int main() {
    int *arr, length, index, key;

    arr = input_array(&length);

    printf("Array: ");
    display_array(arr, length);

    printf("Enter index to add: ");
    scanf("%d", &index);

    printf("Enter value: ");
    scanf("%d", &key);
    arr = add_element(arr, &length, index, key);

    display_array(arr, length);
    
    free(arr);

    return 0;
}

int *add_element(int *arr, int *length, int index, int key) {
    if (index < 0 || index > *length) {
        fprintf(stderr, "Invalid index: %d", index);
        return arr;
    }

    ++(*length);
    arr = (int *)realloc(arr ,*length * sizeof(int));

    if (index == *length - 1) {
        arr[index] = key;
    } else {
        for (int i = *length; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = key;
    }

    return arr;
}
