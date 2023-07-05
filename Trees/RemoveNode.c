#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int FindMin(struct Node* root);
int FindMax(struct Node* root);
struct Node* Delete(struct Node* root, int data);

int main() {
    struct Node* root = NULL;
}

int FindMin(struct Node* root) {
    if (root == NULL) {
        printf("Error: Tree is Empty!\n");
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int FindMax(struct Node* root) {
    if (root == NULL) {
        printf("Error: Tree is Empty!\n");
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}
struct Node* Delete(struct Node* root, int data) { // return type Node because it will alterate the tree
    if (root == NULL) return root; // root is NULL;
    else if (data < root->data) root->left = Delete(root->left, data); // Delete function returns the adress of the modified root of the left-subtree 
    else if (data > root->data) root->right = Delete(root->right, data);
    else {
        // Case 1: No child (Leaf Node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root == NULL;
        }
        // Case 2: One Child 
        else if (root->left == NULL) {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: 2 Children
        else {
            struct Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}