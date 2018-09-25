#include <stdio.h>

char arr_delete[100000];

int stlen(char *str)
{
	int i=0;
	while(str[i])i++;
	return i;
}

char * Delete(char *main_string,int position,int length)
{
	int j,i,sz=stlen(main_string);
	for(i=0;i<100000;i++)arr_delete[i]=0;
	for(i=0;i<position;i++)arr_delete[i]=main_string[i];
	for(j=position+length;j<sz;j++,i++)arr_delete[i]=main_string[j];
	return arr_delete;
}

int main()
{
	char arr[]="hello my world , Bangladesh";
	printf("%s\n", Delete(arr,6,3));
}