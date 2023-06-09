#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Process
typedef struct {
    int identificador;
    char comando[15];
} valueT;

// Node
typedef struct _nodeT {
    valueT value;
    struct _nodeT* next;
} nodeT;

// Stack
typedef struct {
    nodeT *head;
} StackT;

// Functions
nodeT *NewNode(void);
StackT *NewStack(void);

void Push(StackT *stack, valueT processo);
valueT Pop(StackT *stack);

void EmptyStack(StackT *stack);
void FreeStack(StackT *stack);
int isEmpty(StackT *stack);

int main() {
    StackT* myStack = NewStack();
    valueT processo; // variable of type valueT
    processo.identificador = 12345;
    strcmp(processo.comando, "comand");
    Push(myStack, processo);
    Pop(myStack);
    EmptyStack(myStack);
    FreeStack(myStack);
    isEmpty(myStack);
}

// Create a new Stack
StackT *NewStack(void){
    StackT *newStack = (StackT*)malloc(sizeof(StackT)); // malloc alocates memory if not returns NULL
    if (newStack != NULL) {
        newStack->head = NULL; // Set head initially as NULL 
    } else {
        printf("Erro: Não a mais espaço no heap para criar uma Nova Stack");
        return NULL;
    }
    return newStack; // return pointer of type stackT (head)
}

// Push method
void Push(StackT *stack, valueT processo) {
    nodeT* newNode = NewNode(); // alocate memory for a new Node
    if(NewNode == NULL) return;
    // link the Nodes
    newNode->value = processo;
    newNode->next = stack->head;
    stack->head = newNode;
}

// Pop method
valueT Pop(StackT* stack){
    nodeT* nodeTop = stack->head; // Set nodeTop as the adress of the head node
    if(nodeTop == NULL) { // if the top is initial null
        valueT Empty;
        Empty.comando[0] = '\0';
        Empty.identificador = 0;
        printf("Erro: A Stack esta vazia");
        return Empty; // return 0 if the stack is empty
    }
    // fix the links
    stack->head = nodeTop->next; 
    free(nodeTop); // free the Top node
}

// EmptyStack method
void EmptyStack(StackT* stack){
    nodeT* nodeTop = stack->head; // variable initialy points to the head node
    while(nodeTop != NULL) { // while we havn't reached the end of the linked list keep iterating
        nodeT* current = nodeTop; // current initialy points to variable nodeTop
        nodeTop = nodeTop->next; // link the next node at each iteration
        free(current); // keep removing nodes at each iterations 
    }
    // Set head as NULL
    stack->head = NULL; /* we set head as NULL as default so we don't eliminate our stack 
    so when adding a new Node, head is already set as NULL so that we can add a new Node */
}

// FreeStack method
void FreeStack(StackT* stack){
    if(stack->head == NULL) { // if stack is empty
        free(stack); // free the stack
    } else {
        printf("Erro: A stack não esta vazia");
        return;
    }
}

// IsEmpty method
int isEmpty(StackT* stack) {
    nodeT* nodeTop = stack->head;
    int counter = 0;
    if(nodeTop == NULL) {
        counter = 1; // Stack is Empty
    } else counter; // Not Empty

    return counter; // return value
}

// create a new Node
nodeT *NewNode(void) {
    nodeT* newNode = (nodeT*)malloc(sizeof(nodeT)); // alocate memory for the newly created Node
    if (newNode != NULL) return newNode;
    else {
        printf("Erro: Nao a espaço para criar um novo no");
        return NULL;
    }
}