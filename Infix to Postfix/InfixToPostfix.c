#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x);
char pop();
int priority(char x);

int main(){
    char exp[100];
    char *pTr, x;
    printf("Enter the expression: ");
    scanf("%s", exp);
    printf("\n");

    pTr = exp;

    while(*pTr != '\0') {
        if (isalnum(*pTr)) printf("%c ", *pTr);
        else if (*pTr == '(') push(*pTr);
        else if (*pTr == ')') {
            while ((x = pop()) != '(') printf("%c ", x);
        }
        else {
            while(priority(stack[top]) >= priority(*pTr)) printf("%c ", pop());
            push(*pTr);
        }
        pTr++;
    }

    while(top != - 1) {
        printf("%c ", pop());
    } return 0;
}

void push(char x) {
    stack[++top] = x;
}
char pop(){
    if (top == -1) return -1;
    else return stack[top--];
}
int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}