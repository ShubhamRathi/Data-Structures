
#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;

int ans[1000],y=0;
int poans[1000],z=0;

node* newNode(int data)
{
	node* node1 = ( node*)malloc(sizeof( node));
	node1->data = data;
	//printf("New Node->data: %d\n",node1->data);
	node1->left = NULL;
	node1->right = NULL; 
	return node1;
}
node* cartree(int arr[], int s, int e) // Create Cartesian Tree Recursively
{
	if (s > e)
        	return NULL;
	int i = min (arr, s, e);
	node *root = newNode(arr[i]);
	if (s == e)
		return root;
	root->left  = cartree (arr, s, i-1);
	root->right = cartree (arr, i+1, e);

	return root;
}

int min (int arr[], int s, int e) // Find the Minimum Index
{
	int i, min = arr[s], mi=s;
	//printf("min is %d, start is from %d, end is at %d \n",min,s,e);
	//printf("Array Passed: \n");
	for(i = s; i <= e; i++)
	{
		
		if(arr[i] < min)
			{
			min=arr[i];		          
			mi = i;
			}
		
	}
	//printf("\nMin Index: %d and Min Element:%d \n ",mi,arr[mi]);
	return mi;
}



void Postorder( node* tree)
{
	if (tree == NULL)
		return;     
	Postorder(tree->left);      
	Postorder(tree->right);     
	poans[z++]=tree->data;
}

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
	int t,k,n,i;
	scanf("%d",&t);// Test Cases
	for(k=0;k<t;k++)
	{
		
		y=z=0;
		scanf("%d",&n);// No of Elements in the array
		int arr[n];
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);// Scanning the Array
		int len = n;    
		node *root = cartree(arr, 0, len - 1);
		Preorder(root);
		//printf("Pre-Order\n");
		for(i=0;i<len;i++) // Print Pre Order
		{
			if (i==len-1)
				printf("%d\n",ans[i]);
			else
				printf("%d ",ans[i]);
		}		

		Postorder(root);
		//printf("Post Order\n");
		for(i=0;i<len;i++) // Print Post Order
		{
			if (i==len-1)
				printf("%d\n",poans[i]);
			else
				printf("%d ",poans[i]);
		}
	}
	return 0;
}
