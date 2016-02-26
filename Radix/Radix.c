#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    char d[55];
    int len;
    struct Node *next;
}Node;
Node *node[10]={NULL};
Node *tail[10]={NULL};
Node *start=NULL,*end=NULL;
long long int nod(int x) // Maximum number of digits
{
    int d=0;
    while(x)
    {
        x=x/10;
        d++;
    }
    return d;
}
long long int* collect(Node **start,Node **end)
{
    int i=0,j=0;
    Node *new=(*start);
    while(i<10)
    {
        while(node[i])
        {
            strcpy(new->d,node[i]->d);
	    Node *temp=node[i];
            node[i]=node[i]->next;
	    free(temp);
            j++;
	    new=new->next;
        }
	node[i]=NULL;
	tail[i]=NULL;
        i++;
    }
		 // returns the repopulated array in the order
}
void radix(Node **start,Node **end,long long int n,int q)
{
    long long int i,p;
    long long int t;
    long long int j;
    for(i=1;i<=q;i++)
    {
        Node *new=(*start);
        for(j=0;j<n;j++)
        {
	    char *a=new->d;
            p=a[(new->len)-i]-48;
	    if(node[p]==NULL)
	    {	  
		   node[p]=(Node*)malloc(sizeof(Node));
          	   strcpy(node[p]->d,new->d);
           	   node[p]->next=NULL;
		   tail[p]=node[p];
	    }
	    else
	    {                                                        
			 tail[p]->next=(Node*)malloc(sizeof(Node));
			 tail[p]=tail[p]->next;
		   	 strcpy((tail[p]->d),new->d);
		   	 tail[p]->next=NULL;
	    }
	    new=new->next;
        }
        collect(start,end);
    }
}
 int main()
 {
     int t,i;
     long long int n,j;
     scanf("%d",&t);// Test Cases
     char a[55];
     for(i=0;i<t;i++)
     {
	int p,q;
	/*for(p=0;p<10;p++)
	{
		while(node[p])
		{
			Node *temp=node[p];
			node[p]=node[p]->next;
			free(temp);
		}
		node[p]=NULL;
	} // Resetting the Node[] each time a fresh test is made*/
         scanf("%lld",&n);
         for (j=0;j<n;j++)
         {
	     if(start==NULL)
	     {
		     start=(Node*)malloc(sizeof(Node));
		     scanf("%s",start->d);
		     (start->len) = strlen(start->d);
		     end=start;
		     start->next=NULL;
	     }
	     else
	     {
		     end->next=(Node*)malloc(sizeof(Node));
		     end=end->next;
		     scanf("%s",end->d);
		     (end->len) = strlen(end->d);
		     end->next=NULL;
	     }
         } 
	 scanf("%d",&q);
         radix(&start,&end,n,q);
	 while(start)
	 {
		 Node *new=start;
		printf("%s ",new->d);
		start=start->next;
		free(new);
	 }
	 end=NULL;
	 printf("\n");
     }
     return 0;
 }
