#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

bool IsSubtreeLesser(struct Node* root, int value);
bool IsSubtreeGreater(struct Node* root, int value);
bool IsBinarySearchTree(struct Node* root);

int main() {
    struct Node* root = NULL;
}

bool IsSubtreeLesser(struct Node* root, int value) {
    if (root == NULL) return true;
    if (root->data <= value 
    && IsSubtreeLesser(root->left, value) // Recursion to check if node is lesser
    && IsSubtreeLesser(root->right, value)) return true;
    else return false;
}
bool IsSubtreeGreater(struct Node* root, int value) {
    if (root == NULL) return true;
    if (root->data > value 
    && IsSubtreeGreater(root->left, value) // Recursion to check if node is Greater
    && IsSubtreeGreater(root->right, value)) return true;
    else return false;
}
bool IsBinarySearchTree(struct Node* root) {
    if (root == NULL) return true;
    if (IsSubtreeLesser(root->left, root->data) 
    && IsSubtreeGreater(root->right, root->data)
    && IsBinarySearchTree(root->left) // Recursion to check if the Tree is a binary Tree
    && IsBinarySearchTree(root->right)) return true;
    else return false;
}