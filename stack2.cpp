#include <bits/stdc++.h>
using namespace std;


class Stack
{
	Stack *root=NULL;
	int val;
	Stack *next=NULL;
	int sz=0;
	void pr(Stack *curr)
	{
		if(curr!=NULL)
		{
			pr(curr->next);
			printf("%d ",curr->val);
		}
	}
	public:
		void push(int n)
		{
			sz++;
			if(root==NULL)
			{
				root= new Stack;
				root->val=n;
			}
			else
			{
				Stack *ne= new Stack;
				ne->val=n;
				ne->next=root;
				root=ne;
			}
		}
		int size(){return sz;}
		void pop()
		{
			if(root==NULL)return ;
			sz--;
			if(root->next==NULL)
			{
				root=NULL;
				return;
			}
			Stack *cu=root->next;
			delete (root);
			root=cu;
		}
		void print()
		{
			pr(root);
			if(sz)printf("\n");
		}
		int top()
		{
			if(root==NULL)return 1/0;
			return root->val;
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
