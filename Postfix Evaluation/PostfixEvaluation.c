/*
  Evaluation Of postfix Expression in C++ 
  Input Postfix expression must be in a desired format. 
  Operands must be integers and there should be space in between two operands.
  Only '+'  ,  '-'  , '*' and '/'  operators are expected. 
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
    if (top == -1) return 0;
    return array[top--];
}

int Top() {
    return array[top];
}

int main() {
    char* expression = (char*)malloc(MAX_SIZE * sizeof(char));
    printf("Enter Postfix Expression \n");
    scanf("%s", expression);
    int result = EvaluatePostfix(expression);
    printf("Output = %d\n", result);
    free(expression);
    return 0;
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
            int operand2 = Pop();
            int operand1 = Pop();
            // Perform operation
            int result = PerformOperation(expression[i], operand1, operand2);
            // Push back result of operation on stack
            Push(result);
        }
        else if(IsNumericDigit(expression[i])) {
            // Extract the numeric operand from the string
            // Keep incrementing i as long as you getting a numeric digit
            int operand = 0;
            while(i < strlen(expression) && IsNumericDigit(expression[i])) {
                // For a number with more than one digits, as we are scanning from left to right
                /* Everytime, we get a digit towards right, we can multiply current total in operand
                by 10 and add the new digit */
                operand = (operand* 10 ) + (expression[i] - '0');
                i++;
            }
            // Finally, you will come out of while loop with i set to a non-numeric character or end of string
			// decrement i because it will be incremented in increment section of loop once again. 
			// We do not want to skip the non-numeric character by incrementing i twice. 
			i--;

            // Push operand on stack. 
			Push(operand);
        }
    }
    // If expression is in correct format, Stack will finally have one element. This will be the output. 
	if (top != -1) {
        int result = Top();
        top = -1;
        return result;
    }
    printf("Invalid postfix expression. \n");
    return 0;
}

bool IsNumericDigit(char C) {
    if (C >= '0' && C <= '9') return true;
    return false;
} 

bool IsOperator(char C) {
    if (C == '+' || C == '-' || C == '*' || C == '/') return true;
    return false;
}

int PerformOperation(char operation, int operand1, int operand2) {
    if (operation == '+') return operand1 + operand2;
    else if (operation == '-') return operand1 - operand2;
    else if (operation == '*') return operand1 * operand2;
    else if (operation == '/') return operand1 / operand2;
    
    else printf("Unexpected Error \n");
    return -1;
}
