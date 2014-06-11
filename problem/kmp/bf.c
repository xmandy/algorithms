#include <stdio.h>
#include <string.h>


char* bf(char *target, char *pattern)
{
	int i = 0, j = 0;
	while(i < (strlen(target) - strlen(pattern) + 1))
	{
		while(j < strlen(pattern))
		{
			if(target[i + j] == pattern[j])
				j++;
			else
				break;
		}
		if(j == strlen(pattern))
			return target + i;
		j = 0;
		i ++;
	}
	return NULL;
		
}

int main(int argc, const char *argv[])
{
	printf("%s\n", bf("abcdacdcdef", "cdcde"));
	
	return 0;
}
