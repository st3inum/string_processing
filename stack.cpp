#include <bits/stdc++.h>
using namespace std;


class Stack
{
	int arr[100010];
	int i=0;
	public:
		void push(int n){arr[i++]=n;}
		void pop(){if(i>0)i--;}
		void print(){for(int j=0;j<i;j++)cout<<arr[j]<<' ';if(i>0)cout<<endl;}
		int size(){return i;}
		bool empty(){return i==0;}
		int top(){if(i==0)return 1/0;return arr[i-1];}
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
