#include <bits/stdc++.h>
using namespace std;


class Stack
{
	Stack *root=NULL;
	int val;
	Stack *next=NULL;
	int sz=0;
	public:
		void push(int n)
		{
			sz++;
			if(root==NULL)
			{
				root= new Stack;
				root->val=n;
				root->next=NULL;
			}
			else
			{
				Stack *cu=root;
				while(cu->next!=NULL)cu=cu->next;
				Stack *ne= new Stack;
				ne->val=n;
				ne->next=NULL;
				cu->next=ne;
			}
		}
		int size(){return sz;}
		void pop()
		{
			Stack *cu=root;
			if(root==NULL)return ;
			sz--;
			if(root->next==NULL)
			{
				root=NULL;
				return;
			}
			while(cu->next->next!=NULL)cu=cu->next;
			delete (cu->next);
			cu->next=NULL;
		}
		void print()
		{
			Stack *cu=root;
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
		int top()
		{
			Stack *cu=root;
			if(cu==NULL)return 1/0;
			while(cu->next!=NULL)cu=cu->next;
			return cu->val;
		}
		bool empty(){return root==NULL;}
};

int main()
{
	Stack v;
	v.push(10);
	v.pop();
	// cout<<v.top()<<endl;
	cout<<v.size()<<endl;
	v.print();
	v.pop();
	cout<<v.size()<<endl;
	cout<<v.empty()<<endl;
	v.print();
	v.push(10);
	v.push(20);
	v.push(100);
	v.push(90);
	v.push(101);
	v.pop();
	v.push(102);
	v.print();
	cout<<endl;
	cout<<v.top()<<endl;
	cout<<v.size()<<endl;
}
