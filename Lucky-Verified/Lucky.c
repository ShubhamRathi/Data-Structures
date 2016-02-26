#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int a;
	struct list* next;
}list;
int main()
{
	list *node,*m,*k,*pass,*v;
	int test;
	scanf("%d",&test);
	while(test)
	{
		node=(list*) malloc(sizeof(list));
		m=node;// Initial Address of the first node is saved in m
		pass=node;
		int n,y,i;
		//printf("Enter the No. of elements\n");
		scanf("%d",&n);
		int d=0;
		int in;
		i=1;
		while(n>d)
		{
			//printf("Enter the Value in Node %d\n",++d);
			++d;
			scanf("%d",&in);
			//		printf("%d\n",in);
			node->a=in;
			if(d != n)
			{
				node->next=(list*) malloc(sizeof(list));
				node=node->next;
			}
		}
		node->next=m; //Circular LL creation complete
		/*printf("%d\n",node->a);
		printf("%d\n",node->next->a);
		printf("%d\n",node->next->next->a);
		printf("%d\n",node->next->next->next->a);
		printf("%d\n",node->next->next->next->next->a);*/
		
		scanf("%d",&y);
		while(n!=1)
		{
			if (i++!=y-1)
			{
				//printf("%d\n",node->a);
				v=node->next->next;				
				free(node->next);
				node->next=v;
				i=1;
				n--;
			}

			node=node->next;
		}
		printf("%d\n",node->a);
		test--;
	}
	return 0;
}
