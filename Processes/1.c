#include <stdio.h>
#include <stdlib.h>

// Process
typedef struct {
    int identificador;
    char comando;
} valueT;

// Node
typedef struct _nodeT {
    valueT value;
    struct _nodeT* next;
} nodeT;

// stack
typedef struct {
    nodeT *head;
} StackT;

//functions
nodeT *NewNode(void);
StackT *NewStack(void);

void Push(StackT *stack, valueT processo);
valueT Pop(StackT *stack);

void EmptyStack(StackT *stack);
void FreeStack(StackT *stack);
int isEmpty(StackT *stack);

int main() {
    StackT* myStack = NewStack(); // points the new structure NewStack() memory
    Push(myStack, ());
}

// Create a new Stack
StackT *NewStack(void){
    StackT *newStack = (StackT*)malloc(sizeof(StackT)); // malloc alocates memory if not returns NULL
    if (newStack != NULL) { // verify if malloc returns NULL
        newStack->head = NULL; // Set head initially as NULL 
    } else {
        printf("Erro: Não a mais espaço no heap para criar uma Nova Stack");
        return NULL;
    }
    return newStack; // return pointer of type stackT
}

// Push method
void Push(StackT *stack, valueT processo) {

}