#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int top = -1, size;
int IsNumericDigit(char C)
{
	if(C >= '0' && C <= '9') return 1;
	return 0;
}

// Function to verify whether a character is operator symbol or not.
int IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C == '^')
		return 1;

	return 0;
}

// Function to perform an operation and return output.
int PerformOperation(char operation, int operand1, int operand2)
{

	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;
	else if(operation == '^')
	{
		return (int)(pow(operand1,operand2));
	}

	//else printf("Unexpected Error\n");
	return -1;
}

/* push the given data into the stack */
void push(int *stack, int data) {
	top++;
	//printf("Top:%d, Size:%d\n",top,size);
	if (top >= size ) {
		//printf("Stack Overflow\n");
		return;
	}

	//printf("Hello in PUSH\n");
	stack[top] = data;
	return;
}

/* pop the top element from the stack */
void pop(int *stack) {
	if (top <= -1) {
		//printf("Stack Underflow!\n");
		return;
	}
	stack[top] = -1;
	top--;
	return;
}
int peek(int *stack)
{
	return stack[top];
}
void stackp(int *stack)// Print the Stack
{
	int r;
	printf("Print Stack:\n");
	for(r=top;r >-1;r--)
		printf("%d\n",stack[r]);
}

int EvaluatePrefix(char* expression)
{
	int i;
	size=strlen(expression);
	int stack[size];
	if (size == 1)
	{	if(IsNumericDigit(expression[0])){
			push(stack, expression[0]-'0');
			return expression[0]-'0';}
		else
			return -7765;
	}
	/*if (size == 2)
	{	if(IsNumericDigit(expression[0])&& !IsNumericDigit(expression[1]))
			return ((expression[0]-'0')*+expression[0]-'0';
		else
			return -7765;
	}*/
	for( i = strlen(expression)-1;i>-1;i--)
	{
			//printf("Current: %c\n",expression[i]);
		
				//stackp(stack);
		if(IsOperator(expression[i])) {
			if(top>=1)// Only If the stack does have more than 2 operands
			{
			// Pop two operands.
			int operand1 = stack[top]; pop(stack);
			int operand2 = stack[top]; pop(stack);
			// Perform operation
			int result = PerformOperation(expression[i], operand1, operand2);
			//Push back result of operation on stack.
			push(stack,result);
			}
			else
				return -7765;
			
		}
		
		
		else if(IsNumericDigit(expression[i])){

			push(stack,expression[i]-'0');
		}
		
		else 
			return -7765;
	}

	// If expression is in correct format, Stack will finally have one element. This will be the output.
	return stack[top];
}


int main()
{
	int t,u;	
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
			//printf("======================================================================================\n");
		top=-1;
		char expression[100];
		scanf("%s",expression);
		int y=EvaluatePrefix(expression);
		if(top==0 && y!= -7765) // Balancing Parenthesis Check
			printf("%d \n",y);
		else
			printf("invalid\n");
	}
	return 0;
}
