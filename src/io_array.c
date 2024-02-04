#include "io_array.h"

int *input_array(int *);
void display_array(int *, int);

int *input_array(int *length) {
    printf("Enter the length of array: ");
    if (scanf("%d", length) != 1 || *length < 1) {
        perror("Invalid array length.\n");
        exit(1);
    }

    int *arr = (int *)malloc(*length * sizeof(int));
    if (arr == NULL) {
        perror("Dynamic allocate memory error.\n");
        exit(1);
    }

    printf("Enter elements of the arrays: \n");
    for (int i = 0; i < *length; ++i) {
        scanf("%d", arr + i);
    }

    return arr;
}

void display_array(int *arr, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}
