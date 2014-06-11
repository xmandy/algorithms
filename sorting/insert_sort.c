#include <stdio.h>

void insert_sort(int array[], int first, int last)
{
	int i = first;
	int j;
	for( i = first + 1; i < last+1; ++i )
	{
		int temp = array[i];
		for( j = i-1; j > first - 1; --j)
		{
			if(array[j] > temp)
				array[j+1] = array[j];
			else
				break;
		}
		array[j+1] = temp;
	}
}

int main(int argc, const char *argv[])
{
	int a[10] = {100, 9, 50, 8, 89, 3, 4, 10, 20, 50};
	insert_sort(a, 0, 9);
	//merge(a, 0, 0, 1);
	int i = 0;
	while(i < 10) {
		printf("%d ", a[i]);
		++i;
	}
	printf("\n");

	return 0;
}
