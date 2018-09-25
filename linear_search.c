#include <stdio.h>
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

void linear_search(int *arr,size_t size,int element)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i]==element)
		{
			printf("found %d in %d positin\n",element,i);
		}
	}
}

int main()
{
	int arr[]={1,2,3,1,3,2,5};
	size_t t=NELEMS(arr);
	linear_search(arr,t,1);
}