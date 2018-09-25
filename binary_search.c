#include <stdio.h>


int binary_search(int *arr,int l,int r,int element)
{
	if(l>r)return -1;
	if(l==r)
	{
		if(arr[l]==element)return l;
		return -1;
	}
	int m=(l+r)>>1;
	if(arr[m]==element)return m;
	else if(arr[m]>element)binary_search(arr,l,m-1,element);
	else binary_search(arr,m+1,r,element);
}

int main()
{
	int arr[]={1,3,5,7,9},i;
	int t=sizeof(arr)/sizeof(arr[0]);
	int val=binary_search(arr,0,t-1,7);
	printf("%d\n", val);
}