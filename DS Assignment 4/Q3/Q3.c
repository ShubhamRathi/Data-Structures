#include<stdio.h>
#include<stdlib.h>
int Queue[100000],top=0,bot=0;
void Enqueue(int d)
{
	Queue[top++]=d;
}
int Dequeue()
{
//	printf("Bot: %d\n",bot);
	return Queue[bot++];
}
int BFS(int n, int arr[n][n])
{
	int cm=0,v,i,state[n],j,cn,m;
	cn=cm=0;
	for(i=0;i<n;i++)
		state[i]=0;// Initially state of all elements is NOT_VISITED
	int finalans[1000]={0};
	int e,r;
/*	printf("Inside BFS, Printing the passed array\n");
	for(e=0;e<n;e++)
	{
		for(r=0;r<n;r++)
		{
			printf("%d ",arr[e][r]);
		}
		printf("\n");
	}*/
	for(i=0;i<n;i++)
	{
		if(state[i]==0)
		{
			Enqueue(i);
			state[i]=1;// State of i is now IN_PROGRESS
			while(top!=bot)
			{
					v=Dequeue();
					finalans[cn]++;
				//	printf("%d\n",finalans[cn]);	
					for(j=0;j<n;j++)
					{
						if(arr[v][j]==1 && state[j]!=1 && state[j]!=2)
						{
							if(v!=j)
							{
								state[j]=1;
								Enqueue(j);
							}
						}
					}
					state[v]=2;// State of v is VISITED
			}
			cn++;

		}
	}
	cm=0;
	for(i=0;i<cn;i++)
	{
		if(cm<=finalans[i])
			cm=finalans[i];
	}
	return cm;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		top=bot=0;
		scanf("%d",&n);
		int arr[n][n];
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		printf("%d\n",BFS(n,arr));
	}
	return 0;
}
