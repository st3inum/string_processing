#include <bits/stdc++.h>
using namespace std;


class Stack
{
	int arr[100010];
	int i=0;
	public:
		void push(int n){arr[i++]=n;}
		void pop(){i--;}
		void print(){for(int j=0;j<i;j++)cout<<arr[j]<<' ';cout<<endl;}
		int size(){return i;}
};


int main()
{
	Stack v;
	v.push(10);
	v.push(20);
	v.push(100);
	v.push(90);
	v.push(101);
	v.pop();
	v.push(102);
	v.print();
	cout<<v.size()<<endl;
}
