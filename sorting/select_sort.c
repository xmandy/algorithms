#include <stdio.h>

void select_sort(int array[], int first, int last)
{
	int i = first;
	int j;
	for( i = first ; i < last; ++i )
	{
		int min = i;
		int temp;
		for( j = i+1; j < last+1; ++j)
		{
			if(array[j] <  array[min])
				min = j;
		}
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;
	}
}

int main(int argc, const char *argv[])
{
	int a[10] = {100, 9, 50, 8, 89, 3, 4, 10, 20, 50};
	select_sort(a, 0, 9);
	//merge(a, 0, 0, 1);
	int i = 0;
	while(i < 10) {
		printf("%d ", a[i]);
		++i;
	}
	printf("\n");

	return 0;
}
