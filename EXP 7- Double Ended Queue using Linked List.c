#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

struct dequeue {
    struct node* front;
    struct node* rear;
};

struct dequeue* createDequeue() {
    struct dequeue* dq = (struct dequeue*) malloc(sizeof(struct dequeue));
    dq->front = dq->rear = NULL;
    return dq;
}

bool isEmpty(struct dequeue* dq) {
    return (dq->front == NULL);
}

void insertFront(struct dequeue* dq, int data) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = dq->front;

    if (isEmpty(dq)) {
        dq->front = dq->rear = newnode;
    } else {
        dq->front->prev = newnode;
        dq->front = newnode;
    }

    printf("Inserted %d at front\n", data);
}

void insertRear(struct dequeue* dq, int data) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = dq->rear;

    if (isEmpty(dq)) {
        dq->front = dq->rear = newnode;
    } else {
        dq->rear->next = newnode;
        dq->rear = newnode;
    }

    printf("Inserted %d at rear\n", data);
}

void deleteFront(struct dequeue* dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty! Cannot delete.\n");
        return;
    }

    struct node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front) {
        dq->front->prev = NULL;
    } else {
        dq->rear = NULL;
    }

    printf("Deleted %d from front\n", temp->data);
    free(temp);
}

void deleteRear(struct dequeue* dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty! Cannot delete\n");
        return;
    }

    struct node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear) {
        dq->rear->next = NULL;
    } else {
        dq->front = NULL;
    }

    printf("Deleted %d from rear\n", temp->data);
    free(temp);
}

void display(struct dequeue* dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty!\n");
        return;
    }

    struct node* temp = dq->front;
    printf("Dequeue elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    printf("This is a menu-driven program demonstrating double-ended queue: \n\n");
    int choice;

    struct dequeue* dq = createDequeue();  // Create deque once

    while (1) {
        printf("Enter your choice:\n\t0.Create a double-ended queue\n\t1.Insertion from front\n\t2.Insertion from rear\n\t3.Deletion from front\n\t4.Deletion from rear\n\t5.Display the list\n\t6.Exit the program\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int value;
                printf("Enter an element to be inserted at the front: ");
                scanf("%d", &value);
                insertFront(dq, value);
                break;
            }

            case 2: {
                int value;
                printf("Enter an element to be inserted at the rear: ");
                scanf("%d", &value);  // Corrected here
                insertRear(dq, value);  // Corrected to insert at rear
                break;
            }

            case 3: {
                deleteFront(dq);
                break;
            }

            case 4: {
                deleteRear(dq);
                break;
            }

            case 5: {
                display(dq);
                break;
            }

            case 6: {
                exit(0);
            }

            default:
                printf("Invalid choice! Try again\n\n");
        }
    }
    return 0;
}
