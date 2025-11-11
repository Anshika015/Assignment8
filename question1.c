#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    int choice;
    printf("Insert %d to left(that is 1) or right of %d? ", data, root->data);
    scanf("%d", &choice);
    if (choice == 1)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main() {
    struct Node* root = NULL;
    int n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        if (root == NULL)
            root = createNode(value);
        else
            insert(root, value);
    }
    printf("Preorder Traversal: ");
    preorder(root);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("Postorder Traversal: ");
    postorder(root);
    return 0;
}
