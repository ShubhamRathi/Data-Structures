#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

char op[2000];

typedef struct node // For Tree
{
	int val;
	struct node* left;
	struct node* right;
}node;

node * qn[1000];
int qi = 0;
int qf = 0;
node * dequeue()
{
	return qn[qf++];	
}

void enqueue(node * x)
{
	qn[qi++]=x;
	return;
}
void print()
{
	int a = qi;
	int b = qf;
	for(;b<a;b++)
		printf("^^%d^^\n",qn[b]->val);
	return;
}
void populate(node ** tree, int val)
{
	node *temp = NULL;
	if(!(*tree))
	{
		temp = (node*)malloc(sizeof(node));
		temp->left = temp->right = NULL;
		temp->val = val;
		*tree = temp;
		return;
	}

	if(val < (*tree)->val)
	{
		populate(&((*tree)->left), val);
	}
	else if(val > (*tree)->val)
	{
		populate((&(*tree)->right), val);
	}

}
int min = 0;
node * kmin = NULL;
void inorder(node * tree, int k)
{
	if (tree)
	{
		inorder(tree->left, k);
		min++;
		if(min == k)
		{
			kmin = tree;
			return;
		}
		inorder(tree->right, k);
	}
	return;
}

int k=0;
node * layer(int c)
{	
	while(1)
	{
		node* temp=dequeue();
		if (temp == NULL)
		{
//			node * t = dequeue();
//			if(t == NULL)
//				return NULL;
//			enqueue(t);
			enqueue(NULL);
		}
		else
		{
			if(temp->val == c)
			{
				return dequeue();
			}
			if(temp->left!=NULL)
				enqueue(temp->left);
			if(temp->right!=NULL)
				enqueue(temp->right);
		}
//		print();
	}
}

int main()
{
	int t,i,j,n,k,e;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		k=0;
		min = 0;
		qi = 0;
		qf = 0;
		kmin = NULL;
		scanf("%d",&n);
		int arr[n];
		node *root;
		node *tmp;
		//int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		root = NULL;
		for (i=0;i<n;i++)
		{
			populate(&root, arr[i]);
		}// Tree constructed
		scanf("%d%d",&e,&k);
		enqueue(root);
		enqueue(NULL);
		node * rn = layer(e);
		if(rn==NULL)
			printf("$ ");
		else
			printf("%d ",rn->val);
		int flag = 0;
		if(rn == NULL)
			flag = 1;
		if(flag == 0)
			inorder(rn, k);
		if(kmin == NULL)
			printf("$\n");
		else
			printf("%d\n",kmin->val);
	}	
	return 0;

}
