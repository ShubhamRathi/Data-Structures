#include<stdio.h>
#include<stdlib.h>
int ans[1000],y=0;
int poans[1000],z=0;

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;

void populate(node**,int);
void inorder(node*);
//void Preorder(node*);
void Postorder(node*);

void Preorder( node* tree)
{
	if (tree == NULL)
		return; 
	ans[y++]= tree->data; 
	Preorder(tree->left); 
	Preorder(tree->right);
}  

int main()
{
	int r,u,t,n,i;
	scanf("%d",&t);// Test Cases
	for(u=0;u<t;u++)
	{
		y=z=0;		
		scanf("%d",&n);// Array Size
		int in[n],pre[n];
		node *root;
		node *tmp;
		root = NULL;
		for(i=0;i<n;i++)
			scanf("%d",&pre[i]);// Pre Order
		for(i=0;i<n;i++)
			scanf("%d",&in[i]);// In Order 
		scanf("%d",&r); // Scan Root
		populate(&root,r);// Root element as first
		for (i=0;i<n;i++)
		{
			if(pre[i]!=r)
				populate(&root, pre[i]);
		}

		for(i=0;i<n;i++)// Print In-Order
		{	
			if(i==n-1)
				printf("%d\n",in[i]);
			else
				printf("%d ",in[i]);
		}

		Preorder(root);
		for(i=0;i<n;i++) // Print Pre Order
		{
			if (i==n-1)
				printf("%d\n",ans[i]);
			else
				printf("%d ",ans[i]);
		}		

		Postorder(root);
		for(i=0;i<n;i++) // Print Post Order
		{
			if (i==n-1)
				printf("%d\n",poans[i]);
			else
				printf("%d ",poans[i]);
		}


	}
	return 0;

}

void populate(node ** tree, int val)
{
	node *temp = NULL;
	if(!(*tree))
	{
		temp = (node*)malloc(sizeof(node));
		temp->left = temp->right = NULL;
		temp->data = val;
		*tree = temp;
		return;
	}

	if(val < (*tree)->data)
	{
		populate(&((*tree)->left), val);
	}
	else if(val > (*tree)->data)
	{
		populate((&(*tree)->right), val);
	}

}

void Postorder( node* tree)
{
	if (tree == NULL)
		return;     
	Postorder(tree->left);      
	Postorder(tree->right);     
	poans[z++]=tree->data;
}

