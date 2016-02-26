#include <stdio.h>
#include <stdlib.h>

int top = -1, size;

/* push the given data into the stack */
void push(int *stack, int data) {
	top++;
	//printf("Top:%d, Size:%d\n",top,size);
	if (top >= size ) {
		printf("Stack Overflow\n");
		return;
	}

	//clprintf("Hello in PUSH\n");
	stack[top] = data;
	return;
}

/* pop the top element from the stack */
void pop(int *stack) {
	if (top <= -1) {
		printf("Stack Underflow!\n");
		return;
	}
	stack[top] = -8344;
	top--;
	return;
}
char peek(int *stack)
{
	return stack[top];
}
void stackp(int *stack)
{
	int r;
	printf("Print Stack:\n");
	for(r=top;r>=-1;r--)
		printf("%c\n",stack[r]);
}

int check(int q[],int ne,int *stack)
{
	int i;
	for(i=0;i<ne;i++)
	{
		if(q[i]<0)
			push(stack,q[i]);
		else
		{
			if(stack[top]+q[i]==0)
				pop(stack);
			else
			{
				//printf("Invalid");
				return 0;
			}

		}
	}
	if(top==-1)
		return 1;
}

int sum(int a[],int noe)
{
	int i,n,s;
	//printf("Inside sum\n");
	for(i=0;i<(noe);i++)
	{
		n=i-1;
		s=0;
		while(n>=0)
		{
			if(a[n]!=-1)
			{
				s=s+a[n];
				if(s<a[i])
					a[n]=-1;
			}
			n--;
		}
	}
	n=0;
	for(i=0;i<(noe);i++)
	{
		if(a[i]==-1)
			n++;
	}
	//printf("N: %d",n);
	if(n==(noe)-1)
		return 1;
	return 0;
}


int main()
{
	int t,ne,i,j,k=0;;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{

		printf(¨);
		scanf("%d",&ne);
		size=ne;
		//printf("Size/ne= %d",size);
		int stack[size];
		int q[ne]; int a[ne/2];
		for(j=0;j<ne;j++)
		{
			scanf("%d",&q[j]);
			if (q[j]>0)
			{
				a[k]=q[j];
				k++;
				//printf("Hi");
			}
		}
		if(check(q,ne,stack)==1) 
		{
			//printf("Inside Check 1\n");
			if(sum(a,k)==1)
				printf(":-) Matrioshka!\n");
		}
		else
			printf(":-( Try Again.\n");		

	}
	return 0;
}
