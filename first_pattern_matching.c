#include <stdio.h>

int stlen(char *str)
{
	int i=0;
	while(str[i])i++;
	return i;
}

void pattern_matching(char *text,char *pattern)
{
	int i,j,sa=stlen(text),sb=stlen(pattern);
	for(i=0;i+sb<sa;i++)
	{
		int flag=1;
		for(j=0;j<sb;j++)
		{
			if(text[i+j]!=pattern[j])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			printf("pattern found at %d\n",i);
		}
	}
}

int main()
{
	char text[]="hello my world myworld hello world my world",pattern[]="hello";
	pattern_matching(text,pattern);
}