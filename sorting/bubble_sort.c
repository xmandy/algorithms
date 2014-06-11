#include <stdio.h>

void bubble_sort(int array[], int first, int last)
{
	int i = first;
	int j;
	for( i = last; i > 0; --i )
		for( j = 0; j < i; ++j)
		{
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
}

int main(int argc, const char *argv[])
{
	int a[10] = {100, 9, 50, 8, 89, 3, 4, 10, 20, 50};
	bubble_sort(a, 0, 9);
	//merge(a, 0, 0, 1);
	int i = 0;
	while(i < 10) {
		printf("%d ", a[i]);
		++i;
	}
	printf("\n");

	return 0;
}
