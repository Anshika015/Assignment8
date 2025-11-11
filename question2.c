#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert in BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// (a) Search Recursive
struct Node* searchRecursive(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

// (a) Search Non-Recursive
struct Node* searchNonRecursive(struct Node* root, int key) {
    while (root != NULL && root->data != key) {
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// (b) Maximum element
struct Node* findMax(struct Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

// (c) Minimum element
struct Node* findMin(struct Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

// (d) Inorder successor
struct Node* inorderSuccessor(struct Node* root, struct Node* node) {
    if (node->right != NULL)
        return findMin(node->right);

    struct Node* succ = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else
            break;
    }
    return succ;
}

// (e) Inorder predecessor
struct Node* inorderPredecessor(struct Node* root, struct Node* node) {
    if (node->left != NULL)
        return findMax(node->left);

    struct Node* pred = NULL;
    while (root != NULL) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data) {
            root = root->left;
        } else
            break;
    }
    return pred;
}
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, value, key;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\n\nEnter key to search: ");
    scanf("%d", &key);

    struct Node* res1 = searchRecursive(root, key);
    struct Node* res2 = searchNonRecursive(root, key);
    if (res1)
        printf("Found (Recursive)\n");
    else
        printf("Not Found (Recursive)\n");
    if (res2)
        printf("Found (Non-Recursive)\n");
    else
        printf("Not Found (Non-Recursive)\n");

    struct Node* max = findMax(root);
    struct Node* min = findMin(root);
    printf("Maximum: %d\n", max->data);
    printf("Minimum: %d\n", min->data);

    if (res1) {
        struct Node* succ = inorderSuccessor(root, res1);
        struct Node* pred = inorderPredecessor(root, res1);

        if (succ)
            printf("Inorder Successor of %d: %d\n", key, succ->data);
        else
            printf("No Successor for %d\n", key);

        if (pred)
            printf("Inorder Predecessor of %d: %d\n", key, pred->data);
        else
            printf("No Predecessor for %d\n", key);
    }

    return 0;
}
