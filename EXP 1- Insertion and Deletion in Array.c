#include <stdio.h>

#define MAX 100  // Maximum size of the array

// Function to insert an element at a specific position
void insert(int arr[], int *n, int pos, int value) {
    if (*n >= MAX) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    if (pos < 0 || pos > *n) {
        printf("Invalid position.\n");
        return;
    }

    // Shift elements to the right to make space
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;  // Insert the new element
    (*n)++;            // Increase the size of the array
}

// Function to delete an element from a specific position
void delete(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Invalid position.\n");
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;  // Decrease the size of the array
}

// Function to display the array
void display(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX], n = 0;  // Array and its current size
    int choice, pos, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position (0-based index): ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(arr, &n, pos, value);
                break;

            case 2:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;

            case 3:
                display(arr, n);
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
