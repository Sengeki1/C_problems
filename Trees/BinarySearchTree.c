#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BstNode {
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* GetNewNode(int data) { // creat a new node in the heap section and return the address of that node
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    (*newNode).data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct BstNode* Insert(struct BstNode* root, int data) {
    if (root == NULL) { // Empty Tree & Child Node 
        root = GetNewNode(data);
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data); // Recursion
        /* If the value is lesser then the root value insert at the left side of the tree
        using recursion, at each side of a node the pointer left and right is NULL so we create
        a new Node using recursion which the arguments take both the side and the data.*/
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(struct BstNode* root, int data) {
    if (root == NULL) return false;
    else if (root->data == data) return true;
    else if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

int FindMin(struct BstNode* root) {
    if (root == NULL) {
        printf("Error: Tree is Empty!\n");
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int FindMax(struct BstNode* root) {
    if (root == NULL) {
        printf("Error: Tree is Empty!\n");
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int Max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int FindHeight(struct BstNode* root) {
    if (root == NULL) return -1;
    return Max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

int main(){
    struct BstNode* root = NULL; // Empty Tree
    root = Insert(root, 15); root = Insert(root, 10); root = Insert(root, 20);
    root = Insert(root, 25); root = Insert(root, 8); root = Insert(root, 12);
    root = Insert(root, 17);
    int n;
    printf("Enter a number to be searched: ");
    scanf("%d", &n);
    if(Search(root, n) == true) {
        printf("found!\n");
    } else printf("Not found!\n");
    printf("Min value in the Tree %d & Max value in the Tree %d\n", FindMin(root), FindMax(root));
    printf("Height of the Tree: %d\n", FindHeight(root));
}