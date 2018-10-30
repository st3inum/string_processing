#include <bits/stdc++.h>
using namespace std;


class Queue
{
	Queue *root=NULL;
	int val;
	Queue *next=NULL;
	public:
		void push(int n)
		{
			if(root==NULL)
			{
				root= new Queue;
				root->val=n;
				root->next=NULL;
			}
			else
			{
				Queue *cu=root;
				while(cu->next!=NULL)cu=cu->next;
				Queue *ne= new Queue;
				ne->val=n;
				ne->next=NULL;
				cu->next=ne;
			}
		}
		int size()
		{
			Queue *cu=root;
			if(cu==NULL)return 0;
			int i;
			for (i = 1; cu->next!=NULL; ++i)cu=cu->next;
			return i;
		}
		void pop()
		{
			if(root==NULL)return;
			Queue *cu=root->next;
			delete (root);
			root=cu;
		}
		void print()
		{
			Queue *cu=root;
			if(cu==NULL)return ;
			while(1)
			{
				printf("%d ", cu->val);
				if(cu->next==NULL)
				{
					printf("\n");
					break;
				}
				else cu=cu->next;
			}
		}
		int front()
		{
			if(root==NULL)return 1/0;
			return root->val;
		}
		bool empty(){return root==NULL;}
};

int main()
{
	Queue v;
	v.push(10);
	v.pop();
	// cout<<v.front()<<endl;
	cout<<v.size()<<endl;
}