#include <stdio.h>

char arr_insert[100000];

int stlen(char *str)
{
	int i=0;
	while(str[i])i++;
	return i;
}

char * insert(char *main_string,int position,char *sub_string)
{
	int sz1=stlen(main_string),sz2=stlen(sub_string),i,sz=sz1+sz2,j;
	for(i=0;i<100000;i++)arr_insert[i]=0;
	for(i=0;i<position;i++)arr_insert[i]=main_string[i];
	for(j=0;j<sz2;i++,j++)arr_insert[i]=sub_string[j];
	for(j=position;j<sz1;j++,i++)arr_insert[i]=main_string[j];
	return arr_insert;
}

int main()
{
	char arr[]="hello world",sub_arr[]="my ";
	printf("%s\n", insert(arr,6,sub_arr));
}