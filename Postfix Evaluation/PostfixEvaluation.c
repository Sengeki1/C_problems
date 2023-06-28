#include<stdio.h>
#include<string.h>
#define MAX 30
struct stack {
    char str[MAX];
    int top;
}s;

int checkoperand(char ch) {
    if(ch>='0' && ch<='9') return 1;
    return 0;
}

int operator(char ch) {
    if(ch=='*' || ch=='+' || ch=='/' || ch=='-') return 1;
    return 0;
}

void push(int data) {
    s.top++;
    s.str[s.top] = data;
}

char peek() {
    return s.str[s.top];
}

void pop() {
    s.top--;
}

int operation(int x, int y, char op)
{
if(op == '+') return y+x;
else if(op == '-') return y-x;
else if(op == '*') return y*x;
else if(op == '/') return y/x;
else return 0;
}

void evaluation() {
    int i, x, y;
    char postfix[MAX];
    printf("Enter postfix: ");
    scanf("%s",&postfix);
    for(i = 0; i < strlen(postfix);) {
        if(checkoperand(postfix[i]))
            push(postfix[i++]-'0');
        else if(operator(postfix[i])){
            x = peek();
            pop();
            y = peek();
            pop();
            push(operation(x,y,postfix[i]));
            i++;
        }
    }
    printf("%d",s.str[s.top]);
}

int main() {
    s.top = -1;
    evaluation();
    return 0;
}
