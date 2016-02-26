#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top = -1, size;
int IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C == '^')
		return 1;

	return 0;
}

int precedence(char c)
{
	if (c=='+' || c=='-')
		return 1;
	if (c=='*' || c=='/')
		return 2;
	if (c=='^')
		return 3;

	return 0;
}

/* push the given data into the stack */
void push(char *stack, char data) 
{
	top++;
	//printf("Top:%d, Size:%d\n",top,size);
	if (top >= size ) 
	{
		//printf("Stack Overflow\n");
		return;
	}

	//clprintf("Hello in PUSH\n");
	stack[top] = data;
	return;
}

/* pop the top element from the stack */
void pop(char *stack) {
	if (top <= -1) {
		//printf("Stack Underflow!\n");
		return;
	}
	stack[top] = '*';
	top--;
	return;
}
char peek(char *stack)
{
	return stack[top];
}
void stackp(char *stack)
{
	int r;
	printf("Print Stack:\n");
	for(r=top;r>=-1;r--)
		printf("%c\n",stack[r]);
}
int main()
{

	char ip[100];
	int i,k,test,kj=0;
	scanf("%d",&test);
	while(test)
	{

		//printf("=====*===========================*=====================================*=================*=================\n");
		scanf("%s", ip);
		kj=0;
		top=-1;
		size=strlen(ip);
		char op[size+1];
		char stack[size];
		k=0;
		for(i=size-1;i>-1;i--)
		{

			if (IsOperator(ip[i]) && IsOperator(ip[i-1]))
			{
				printf("invalid\n");
				kj=1;
				break;
			}
			if(ip[i]==')' && IsOperator(ip[i-1]))
			{
				printf("invalid\n");
				kj=1;
				break;
			}	    
			//printf("Test is %d\n",test);
			//printf("____________________________________________________________________________________\n");
			//stackp(stack);// Print Stack
			//printf("Top is %d\n",top);
			//printf("Current Token: %c \n",ip[i]);// Print current element
			if (ip[i]==')')
			{
				push(stack,ip[i]);
			}
			else if( (ip[i]-'0')>=0 && (ip[i]-'0')<=9 )// If Number, stdout
			{
			//	printf("if(((ip[i]-'0')>=0 && (ip[i]-'0'))<=9)\n");			
				op[k++]=ip[i];

			}

			else if( (top!=-1) && (ip[i]=='(') )//close Brackets Condition
			{
			//	printf("else if(top!=-1 && ip[i]=='(')//close Brackets Condition)\n");			
				while(stack[top]!=')')
				{

					op[k++]=stack[top];
					pop(stack);
				}
				if(stack[top]==')')
					pop(stack);

			}
			else if(top!=-1 && (precedence(stack[top])-precedence(ip[i])>=0) )// If its a operator, check if pop has to be done.
			{
			//	printf("else if(top!=-1 && (precedence(stack[top])-precedence(ip[i])>0) ))\n");						
				while((precedence(stack[top])-precedence(ip[i])>0 || ((stack[top])=='^' && (ip[i])=='^')) && top!=-1 )
				{

					op[k++]=stack[top];
					pop(stack);				

				}
				push(stack,ip[i]);// Pushing the current token ( with whom comparison was happening)
			}

			else
			{
			//	printf("Checking Else Push\n");			
				push(stack,ip[i]);
			}


		}
		if(kj==0)
		{
			while(top>-1 )// Popping the remaining
			{
				if(stack[top]!='(' && stack[top]!=')' )
				{		
					op[k++]=stack[top];
				}
				pop(stack);
			}
			while(k>0)
			{
				putchar(op[k-1]);
				k--;
			}
			printf("\n");
		}
		
		test--;

	}
	return 0;
}
