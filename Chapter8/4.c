//дһ����������һ��������������

#include <stdio.h>
#include <string.h>

void swap(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp; 
}

void permutate(char* str, int begin, int end)
{
	int i;

	if(begin == end)
	{
		printf("%s\n",str);
	}
	else
	{
		for(i = begin; i < end; i++)
        	{
           	 	swap(str+begin, str+i);//������ַ�
            		permutate(str, begin+1, end);
            		swap(str+begin, str+i); //�ָ�
        	} 
    	} 
}

int main (int argc, const char * argv[]) 
{
    	char str[] = "abcd";
   	int len = strlen(str);
    	permutate(str, 0, len);

	return 0;
}