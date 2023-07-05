#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
    struct Node* data;
    struct Queue* next;
}Queue;
Queue* front = NULL;
Queue* rear = NULL;

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

bool isEmpty();
void Enqueue(struct Node* x);
void Dequeue();
void LevelOrder(struct Node* root);
struct Node* GetNewNode(char data);
struct Node* Insert(struct Node* root, char data);

int main() {

}
// Queue functions
bool isEmpty(){
    if (front == NULL && rear == NULL) return true;
    else return false;
}
void Enqueue(struct Node* x) {
    Queue* current = (Queue*)malloc(sizeof(Queue));
    current->data = x;
    current->next = NULL;
    if (isEmpty()) { // if there is one element in the Queue
        front = rear = current;
    }
    rear->next = current; 
    rear = current;
}
void Dequeue() {
    Queue* temp = front;
    if (front == NULL) return;
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    free(temp);
}
struct Node* Front() {
    struct Queue* temp = front;
}
// Binary Tree
struct Node* GetNewNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    (*newNode).data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* Insert(struct Node* root, char data) {
    if (root == NULL) {
        root = GetNewNode(data);
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    } 
    return root;
}
// Level-Order Traversal
void LevelOrder(struct Node* root) {
    if (root == NULL) return;
    Enqueue(root);
    //while there is at least one discovered node
    while(!isEmpty()) { 
        struct Node* current = Front();
        printf("%c ", current->data);
        if (current->left != NULL) Enqueue(current->left);
        if (current->right != NULL) Enqueue(current->right);
        Dequeue(); // removing the element at front
    }
}