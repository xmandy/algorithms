#include <stdio.h>
#include <stdlib.h>

#define N 5
int d[N+1][N+1];
int res[N+1][N+1];

/* the triangle is
 *           7
 *         3   8
 *       8   1   0
 *     2   7   4   4
 *   4   5   2   6   5
 */

int main(int argc, const char *argv[])
{
	int i, j;
	int rev;

	d[1][1] = 7;
	d[2][1] = 3;
	d[2][2] = 8;
	d[3][1] = 8;
	d[3][2] = 1;
	d[3][3] = 0;
	d[4][1] = 2;
	d[4][2] = 7;
	d[4][3] = 4;
	d[4][4] = 4;
	d[5][1] = 4;
	d[5][2] = 5;
	d[5][3] = 2;
	d[5][4] = 6;
	d[5][5] = 5;
	
	for(i = 1; i < N+1; ++i)
		for(j = 1; j < N+1; ++j)
		{
			printf("%d ", d[i][j]);
			if(j == N)
				printf("\n");
			res[i][j] = -1;
		}

	for(i = 5; i > 0; --i)
		for(j = 1; j <= i; ++j)
		{
			if(i == 5)
				res[i][j] = d[i][j];
			else {
				int temp = res[i+1][j] > res[i+1][j+1] ? res[i+1][j] : res[i+1][j+1];
				res[i][j] = temp + d[i][j];
			}
		}

	for(i = 1; i < N+1; ++i)
		for(j = 1; j < N+1; ++j)
		{
			printf("%d ", res[i][j]);
			if(j == N)
				printf("\n");

		}

	rev = res[1][1] - d[1][1];
	i = 1;
	j = 1;
	printf("(%d, %d)\n", i, j);
	while(1) {
		if(N == i) {
		//	printf("(%d, %d)\n", i, j);
			break;
		}
		if(res[i+1][j] == rev) {
			i++;
			printf("(%d, %d)\n", i, j);
			rev = rev - d[i][j];
		}
		else if (res[i+1][j+1] == rev){
			i++;
			j++;
			printf("(%d, %d)\n", i, j);
			rev = rev - d[i][j];
		}
	}
	
	return 0;
}
