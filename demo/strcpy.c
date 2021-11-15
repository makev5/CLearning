#include <stdio.h>
#include <string.h>

int main()
{
	char s1[] = "abc";
	char s2[] = "abcd";
	strcpy(s1, s2);
	
	printf(s1);
	
	return 0;
	   
}
