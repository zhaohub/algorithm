#include <stdio.h>
void power_set(char* src,char* dst,int i,int len)
{	
	if(i>len-1)
	{
		printf("{%s}\n",dst);
	}else
	{	
		//char* str_tmp=(char*)malloc(sizeof(char)*len);
		//strncpy(str_tmp,src,i+1);
		dst[i]=src[i];
		power_set(src,dst,i+1,len);	
		dst[i]='*';
		//str_tmp[i]='\0';
		//strncpy(str_tmp,src,i);
		power_set(src,dst,i+1,len);	
	}
}
void main(void)
{
	char* str="abcdefg";
	char* dst=(char*)malloc(sizeof(char)*7);
	power_set(str,dst,0,7);
}
