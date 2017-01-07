#include "heap.h"

using namespace std;
void minheapify(int arr[][2], int i, int n ) {
	int l = 2*i;
	int r = 2*i + 1;
	int index;
	if (l <= n && arr[l][0] < arr[i][0])
		index = l;
	else 
		index = i;
		
	if (r <= n && arr[r][0] < arr[index][0])
		index = r;
	if (index != i) {
		swap(arr[i][0], arr[index][0]);
		swap(arr[i][1] , arr[index][1]);
		minheapify(arr, index, n);
	}
}

void build_min_heap(int a[][2], int n) {
	int i;
	for (i = n / 2; i >= 1; i--) {
	minheapify(a, i, n);
	}
}

/*void heapsort(int arr[], int n) {
	int i;
	build_min_heap(arr, n);
	for (i = n; i >= 1; i--) {
		swap(arr[1], arr[i]);
		n--;
		minheapify(arr, 1, n);
	}
}*/

