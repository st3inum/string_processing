#include <bits/stdc++.h>
using namespace std;


class BST
{
	BST *root=NULL;
	int val;
	BST *right=NULL,*left=NULL;
	int sz=0;
	void pr(BST *cu)
	{
		if(cu!=NULL)
		{
			pr(cu->left);
			printf("%d ",cu->val);
			pr(cu->right);
		}
	}
	BST *ansprev=NULL,*anscurr=NULL;
	void fi(int n,int i,BST *cu,BST *pr,bool f)
	{
		if(cu!=NULL)
		{
			if(n==i)
			{
				f=0;
				anscurr=cu;
				ansprev=pr;
				return;
			}
			if(f)fi(n,2*i,cu->left,cu,f);
			if(f)fi(n,2*i+1,cu->right,cu,f);
		}
	}
	public:
		void push(int n)
		{
			sz++;
			if(root==NULL)
			{
				root= new BST;
				root->val=n;
			}
			else
			{
				BST *cu=root;
				while(1)
				{
					if(cu->val>n)
					{
						if(cu->left==NULL)
						{
							BST *ne=new BST;
							ne->val=n;
							cu->left=ne;
							break;
						}
						cu=cu->left;
					}
					else 
					{
						if(cu->right==NULL)
						{
							BST *ne=new BST;
							ne->val=n;
							cu->right=ne;
							break;
						}
						cu=cu->right;
					}
				}
			}
		}
		int size(){return sz;}
		bool empty(){return root==NULL;}
		void print()
		{
			pr(root);
			if(root!=NULL)printf("\n");
		}
		int index(int n)
		{
			anscurr=NULL;
			ansprev=NULL;
			fi(n,1,root,NULL,1);
			if(anscurr==NULL)return -1000000000;
			return anscurr->val;
		}
		void pop(int n)
		{
			anscurr=NULL;
			ansprev=NULL;
			fi(n,1,root,NULL,1);
			if(anscurr==NULL)return;
			if(n==1 && root->left==NULL && root->right==NULL)
			{
				delete (root);
				root=NULL;
				return ;
			}
			if(anscurr->left==NULL && anscurr->right==NULL)
			{
				delete(anscurr);
				if(n%2==0)ansprev->left==NULL;
				else ansprev->right=NULL;
			}
			if((anscurr->left==NULL)^(anscurr->right==NULL))
			{
				if(n%2==0)
				{
					if(anscurr->left==NULL)ansprev->left=anscurr->right;
					else ansprev->left=anscurr->left;
				}
				else
				{
					if(anscurr->left==NULL)ansprev->right=anscurr->right;
					else ansprev->right=anscurr->left;
				}
				delete(anscurr);
			}
			else
			{
				BST *cu=anscurr->right;
				int p=n*2+1;
				while(cu->left!=NULL)cu=cu->left,p*=2;
				anscurr->val=cu->val;
				pop(p);
			}

		}
};

int main()
{
	BST v;
	int arr[]={10,4,20,21,15,3,7,5,8,6};
	for(int i=0;i<10;i++)v.push(arr[i]);
	v.print();
	cout<<v.size()<<endl;
	cout<<v.index(1)<<endl;
	cout<<v.index(10)<<endl;
	v.pop(10);
	v.print();
}
