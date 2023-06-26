/*
  Infix to postfix conversion in C++ 
  Input Postfix expression must be in a desired format. 
  Operands and operator, both must be single character.
  Only '+'  ,  '-'  , '*', '/' and '$' (for exponentiation)  operators are expected. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 101

// Function to evaluate Postfix expression and return output
int EvaluatePostfix(char* expression);

// Function to perform an operation and return output. 
int PerformOperation(char operation, int operand1, int operand2);

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C);

// Function to verify whether a character is numeric digit. 
bool IsNumericDigit(char C);

// Stack to store the operator
int array[MAX_SIZE];
int top = -1;

void Push(int value_) {
    if (top == MAX_SIZE - 1) return;
    array[++top] = value_;
}

int Pop() {
    if (top == -1) return;
    top--;
}

int Top() {
    return array[top];
}

int main() {
    char* expression;
    printf("Enter Postfix Expression \n");
    scanf("%s", expression);
    int result = EvaluatePostfix(expression);
    printf("Output = %d\n", result);
}

int EvaluatePostfix(char* expression) {
    for(int i = 0; i < strlen(expression); i++) {
        // scanning each character from left
        // if caracter is a delimiter, move on
        if (expression[i] == ' ' || expression[i] == ',')continue;
        
        /* If character is operator, pop two elements from stack, perform operation 
        and push the result */
        else if(IsOperator(expression[i])) {
            // Pop two operands
            int operand2 = Top(); Pop();
            int operand1 = Top(); Pop();
            // Perform operation
            int result = PerformOperation(expression[i], operand1, operand2);
            // Push back result of operation on stack
            Push(result);
        }
        else if(IsNumericDigit(expression[i])) {
            //Extract the numeric
        }
    }
}

