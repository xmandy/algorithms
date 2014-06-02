#include <stdio.h>
#include <stdlib.h>

int n = 10;
int m = 5;
// the matrix is m row, n columns
int w[5] = {2, 2, 6, 5, 4};
int v[5] = {6, 10, 5, 4, 6};

int main(int argc, const char *argv[])
{
	int i, j;
	int rows = m+1;
	int columns = n+1;
	

	int *temp = (int *)malloc(sizeof(int)*(rows)*(columns));
	int **matrix = (int **)malloc(sizeof(int *)*(rows));
	int *res = (int *)malloc(sizeof(int)*m);
	for(i = 0; i < rows; ++i)
		matrix[i] = temp + i*columns;
	for(i = 0; i < rows; ++i)
		for(j = 0; j < columns; ++j)
			matrix[i][j] = 0;

	for(i = 1; i < rows; ++i)
		for(j = 1; j < columns; ++j)
		{
			int old = matrix[i-1][j];
			int new = 0;
			if(j >= w[i-1])
				new = matrix[i-1][j - w[i-1]] + v[i-1];
			matrix[i][j] = new > old ? new:old;
		}

	// print the matrix
	for(i = 0; i < rows; ++i)
		for(j = 0; j < columns; ++j)
		{
			printf("%d ", matrix[i][j]);
			if(j == columns - 1)
				printf("\n");
		}

	// calculate the optimal answer
	j = columns - 1;
	for(i = rows - 1; i > 0; --i)
	{
		if(matrix[i][j] == matrix[i-1][j])
			res[i-1] = 0;
		else {
			res[i-1] = 1;
			j = j-w[i-1];
		}	
	}

	// print the optimal answer
	printf("\n");
	for(i = 0; i < m; ++i)
		printf("%d ", res[i]);
	printf("\n");

	free(res);
	free(matrix);
	free(temp);


	

	return 0;
}
