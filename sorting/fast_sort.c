#include <stdio.h>
#include <stdlib.h>

void fast_sort(int a[], int first, int last)
{
	if(first < last) {
		// i as a hole, find a element samller from the end inserting in it
		// then find a element bigger from front inserting the new hole
		// until i = j
		int i = first, j = last;
		int token = a[i];
		while(i < j) {
			while(i < j && a[j] >= token) {
				--j;
			}
			if(i < j) {
				a[i] = a[j];
				++i;
				while(i < j && a[i] < token) {
					++i;
				}
				if(i < j) {
					a[j] = a[i];
					--j;
				}
			}
		}
		a[i] = token;
		fast_sort(a, first, i-1);
		fast_sort(a, i+1, last);
	}
}

int main(int argc, char **argv)
{
	int a[10] = {10, 35, 3, 4, 56, 25, 24, 25, 45, 100};
	fast_sort(a, 0, 9);

	int i = 0;
	while(i < 10) {
		printf("%d ", a[i]);
		++i;
	}
	printf("\n");
}
