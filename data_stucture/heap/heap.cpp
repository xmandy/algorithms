#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

template <typename T>
void displayOneLevel(T x[], int numRows, int level, int beginIndex, int endIndex)
{
	int skip = int(pow(2.0, numRows - level) - 1);
	for(int i = beginIndex; i <= endIndex; ++i)
	{
		cout << setw(skip) << " ";
		cout << setw(2) << x[i];
		cout << setw(skip) << " ";
	}
	cout << "\n\n";
}

template <typename T>
void display(T x[], int n)
{
	int beginIndex = 0, //the first index in a row
		endIndex = 0, // the last index in a row
		rowLength,  // the length of the current row
		numLevels = int(ceil(log(double(n))) /  log(2.0));

	for(int level = 0; level < numLevels; ++level)
	{
		displayOneLevel(x, numLevels, level, beginIndex, endIndex);
		rowLength = endIndex - beginIndex + 1;
		beginIndex = endIndex + 1;
		endIndex = min(endIndex + 2*rowLength, n - 1);
	}
}

// 如果一棵二叉树，只有头部不满足堆的性质
// 可使用下降算法，将头部通过循环/遍历逐层
// 下降，将子树中的较大者上移，然后重复次过程
// start: the heap first element
// end: the heap last element
// r : the only element that is not compotable with max heap.
template <typename T>
void down(T *start, T *end, int r)
{
	T *from = start + r;
	int index = r+1;
	int oldIndex = index;
	index = 2*(index);
	T *target = from + index - oldIndex; // the node to exchange with start, is the left subtree first

	while(target <= end)
	{
		if(target < end && *(target) < *(target + 1)) // if the right node exists and larger than left
		{
			target = target + 1;
			index = index + 1;
		}
		cout<<*target<<endl;
		cout<<index<<endl;
		if(*target > *from)
		{
			T temp = *from;
			*from = *target;
			*target = temp;
		}

		from = target;
		oldIndex = index;
		index *= 2;
		target = from  + index - oldIndex;
	}

}

template <typename T>
void make_heap(T *start, T *end)
{
	
}

// x: the array
// r: the not compatible index of heap, the index of array is r-1
// n: the size of array == the size of heap 
template<typename T>
void down_s(T x[], int r, int n)
{
	if(r > n)
		return;
	int index = r;
	int target = 2*index;
	while(target <= n)
	{
		if(target < n && x[target-1] < x[target]) // has right child, find the larger one.
		{
			target += 1;
		}
		if(x[index - 1] < x[target - 1])
		{
			T temp = x[index - 1];
			x[index - 1] = x[target - 1];
			x[target - 1] = temp;
		}
		else {
			break;
		}
		index = target;
		target = target*2;
	}
}

// for making heap from array, from the first node that has
// no child doing the down method
template <typename T>
void make_heap_s(T x[], int n)
{
	int start = n/2;
	while(start>0)
	{
		down_s(x, start, n);
		start --;
	}
}

template <typename T>
void up_s(T x[], int n, T item)
{
	int start = (n+1);
	int parent = start/2;
	x[n] = item;
	while(parent > 0 && x[parent - 1] < x[start - 1])
	{
		T temp = x[start-1];
		x[start - 1] = x[parent -1];
		x[parent-1] = temp;
		start = parent;
		parent = start/2;
	}
}

template <typename T>
void heap_sort(T x[], int n)
{
	int index = n;
	while (index > 1)
	{
		T temp = x[index - 1];
		x[index - 1] = x[0];
		x[0] = temp;
		down_s(x, 1, index - 1);
		index --;
	}


}




int main(int argc, const char *argv[])
{
	int x[20] = {87, 35, 75, 67, 79, 84, 76, 73, 81, 32};
	int y[8] = {30, 80, 60, 40, 20, 50, 1, 10};
	display(x, 10);
    //down_s(y, 1, 8);
	make_heap_s(x, 10);
	display(x, 10);
	up_s(x, 10, 100);
	display(x, 11);

	heap_sort(x, 11);
	for(int i = 0; i < 11; ++i)
	{
		cout<< x[i] << " ";
	}
	cout << endl;
	
	return 0;
}
