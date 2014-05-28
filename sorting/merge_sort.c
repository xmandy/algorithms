#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int first, int mid, int last)
{
	int length = last - first + 1;
	int *temp = (int*)malloc(length*sizeof(int));
	int i = first, j = mid + 1, k = 0;
	while(i <= mid && j <= last) {
		if(a[i] < a[j]) {
			temp[k] = a[i];
			++i;
		}
		else {
			temp[k] = a[j];
			++j;
		}
		++k;
	}

	while(i <= mid) {
		temp[k] = a[i];
		++i;
		++k;
	}
	while(j <= last) {
		temp[k] = a[j];
		++j;
		++k;
	}
	k = 0;

	// array a starts from first, array temp starts from 0.
	i = first;
	while(k < length) {
		a[i] = temp[k];
		++k;
		++i;
	}
	free(temp);
}

void merge_sort(int a[], int first, int last)
{
	if(first < last) {
		int mid = (first + last)/2;
		merge_sort(a, first, mid);
		merge_sort(a, mid + 1, last);
		merge(a, first, mid, last);
	}

}

int main(int argc, char **argv)
{
	int a[10] = {2, 5, 6, 8, 89, 3, 4, 10, 20, 50};
	merge_sort(a, 0, 9);
	//merge(a, 0, 0, 1);
	int i = 0;
	while(i < 10) {
		printf("%d ", a[i]);
		++i;
	}
	printf("\n");
}
