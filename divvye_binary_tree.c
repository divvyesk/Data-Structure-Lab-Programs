#include <stdio.h>
#include <stdlib.h>

// Structure for a node in Binary Search Tree (BST)
struct Node {
    int data;              // Stores the value of the node
    struct Node* left;     // Pointer to the left child
    struct Node* right;    // Pointer to the right child
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));//allocates space for a new node
    newNode->data = data; //stores the input data in the data section of the node
    newNode->left = newNode->right = NULL;// makes the left and right child as null
    return newNode;
}

// Function to insert a node into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {  // If the tree is empty, create a new node
        return createNode(data);
    }
    if (data < root->data) {  // If data is smaller, insert into the left subtree
        root->left = insert(root->left, data);
    } else if (data > root->data) {  // If data is larger, insert into the right subtree
        root->right = insert(root->right, data);
    }
    return root;  // Return the modified root
}

// Function to find the height of the tree
int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left); //compute height of left subtree
    int rightHeight = height(root->right); //compute height of right subtree
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; //returns the maximum height
}

// Function to count the number of leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to count the number of internal nodes
int countInternalNodes(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

// Function to count total number of nodes
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to find the smallest node
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find the largest node
struct Node* findMax(struct Node* root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to delete a node
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to search for a node
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);         // Traverse left subtree
        printf("%d ", root->data);   // Visit node
        inorder(root->right);        // Traverse right subtree
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);   // Visit node
        preorder(root->left);        // Traverse left subtree
        preorder(root->right);       // Traverse right subtree
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);       // Traverse left subtree
        postorder(root->right);      // Traverse right subtree
        printf("%d ", root->data);   // Visit node
    }
}

// Main function with menu
int main() {
    struct Node* root = NULL;  // Initialize root of BST
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert node\n");
        printf("2. Inorder traversal\n");
        printf("3. Preorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Height of tree\n");
        printf("6. Count leaf nodes\n");
        printf("7. Count internal nodes\n");
        printf("8. Count total nodes\n");
        printf("9. Find smallest node\n");
        printf("10. Find largest node\n");
        printf("11. Delete node\n");
        printf("12. Search for a node\n");
        printf("13. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Height of tree: %d\n", height(root));
                break;
            case 6:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 7:
                printf("Number of internal nodes: %d\n", countInternalNodes(root));
                break;
            case 8:
                printf("Total number of nodes: %d\n", countNodes(root));
                break;
            case 9:
                if (root != NULL) {
                    struct Node* minNode = findMin(root);
                    printf("Smallest node: %d\n", minNode->data);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 10:
                if (root != NULL) {
                    struct Node* maxNode = findMax(root);
                    printf("Largest node: %d\n", maxNode->data);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 11:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 12:
                printf("Enter value to search: ");
                scanf("%d", &data);
                struct Node* searchResult = search(root, data);
                if (searchResult != NULL) {
                    printf("Node found: %d\n", searchResult->data);
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 13:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 13);

    return 0;
}
