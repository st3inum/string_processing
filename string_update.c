#include <stdio.h>
char new_pattern[100000];
int stlen(char *str)
{
	int i=0;
	while(str[i])i++;
	return i;
}

char *  update(char *text,char *pattern_to_replace,char * pattern_to_insert)
{
	int i,j,sa=stlen(text),sb=stlen(pattern_to_replace),k,l,sc=stlen(pattern_to_insert);
	for(i=0;i<100000;i++)new_pattern[i]=0;
	for(i=0,k=0;i+sb<sa;i++)
	{
		int flag=1;
		for(j=0;j<sb;j++)
		{
			if(text[i+j]!=pattern_to_replace[j])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			for(l=0;l<sc;l++,k++)
			{
				new_pattern[k]=pattern_to_insert[l];
			}
			i+=sb-1;
		}
		else
		{
			new_pattern[k++]=text[i];
		}
	}
	for(;i<sa;i++)new_pattern[k++]=text[i];
	return new_pattern;
}

int main()
{
	char text[]="hello my world myworld hello world my world",pattern_to_replace[]="my",pattern_to_insert[]="our";
	printf("%s\n", update(text,pattern_to_replace,pattern_to_insert));
}