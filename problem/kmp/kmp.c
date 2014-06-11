#include <stdio.h>
#include <string.h>

void makeNext(const char *pattern, int next[])
{
	int p_index, n;
	int len = strlen(pattern);
	next[0] = 0;
	for(p_index = 1, n = 0; p_index < len; ++p_index)
	{
		while(n > 0 && pattern[p_index] != pattern[n])
			n = next[n - 1];
		if(pattern[p_index] == pattern[n])
			n ++;
		next[p_index] = n;
	}
}

const char * kmp(const char *target, const char *pattern, int next[])
{
	int n, m;
	int i, q;
	n = strlen(target);
	m = strlen(pattern);
	makeNext(pattern, next);
	for(i = 0, q = 0; i < n; ++i)
	{
		while(q > 0 && pattern[q] != target[i])
			q = next[q-1];
		if(pattern[q] == target[i])
			++q;
		if(q == m)
			return target + i - m + 1;
	}

	return NULL;
}

int main(int argc, const char *argv[])
{
	int next[20];
	int i;
	char *pattern = "abcaabcabf";
	char *target = "dddaabcaabcabfdddde";
	makeNext(pattern, next);
	for(i = 0; i < strlen(pattern); ++i)
		printf("%d ", next[i]);
	printf("\n%s\n",  kmp(target, pattern, next));
	
	return 0;
}
