#include <bits/stdc++.h>
using namespace std;


struct node
{
	int val;
	node *next=NULL;
};
node *root=NULL;

void insert(int val)
{
	if(root==NULL)
	{
		root=new node;
		root->val=val;
	}
	else
	{
		node *cu=root;
		while(cu->next!=NULL)cu=cu->next;
		node *ne=new node;
		ne->val=val;
		cu->next=ne;
	}
}
void print()
{
	node *cu=root;
	while(cu!=NULL)
	{
		printf("%d ",cu->val);
		cu=cu->next;
	}
	printf("\n");
}


int main()
{
	insert(10);
	insert(12);
	insert(0);
	insert(3);
	print();
}