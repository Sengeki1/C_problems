// Function to find Inorder Successor in a BST

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to find successor
struct Node* Getsuccessor(struct Node* root, int data);
struct Node* Find(struct Node* root, int data);
int main() {

}
struct Node* Find(struct Node* root, int data) {
    if (root == NULL) return root;
    else if (root->data == data) return root;
    else if (root->data <= data) return Find(root->left, data);
    else return Find(root->right, data);
}
struct Node* Getsuccessor(struct Node* root, int data) {
    // Search the Node - O(h)
    struct Node* current = Find(root, data);
    if (current == NULL) return NULL;
    // Case 1: Node has right subtree
    if (current->right != NULL){
        struct Node* temp = current->right;
        while (temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }
    // Case 2: No right subtree
    else {
        struct Node* successor = NULL;
        struct Node* ancestor = root;
        while (ancestor != current) { 
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left; // Traverse to find a depper node
            }
            else { // if ancestor lies in the right of the subtree
                ancestor = ancestor->right;
            }
            return successor;   
        }
    }
    
}
