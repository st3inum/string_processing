#include <stdio.h>


void bubble_sort(int *arr, size_t size)
{
	int i,j,temp;
	for(i=0;i<size;i++)
	{
		for(j=0;j+1<size;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int main()
{
	int arr[]={7,1,2,8,3,1,3,2,5},i;
	size_t t=sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,t);
	for(i=0;i<t;i++)printf("%d ",arr[i]);
}