#include "heap.h"



using namespace std;

typedef pair <int , int > pp ;
void minheapify(int arr[][2], int i, int n , int index[]) {
	int l = 2*i;
	int r = 2*i + 1;
	int ind;
	if (l <= n && arr[l][0] < arr[i][0])
		ind = l;
	else 
		ind = i;
		
	if (r <= n && arr[r][0] < arr[ind][0])
		ind = r;
	if (ind != i) {
		swap(arr[i][0], arr[ind][0]);
		swap(arr[i][1] , arr[ind][1]);
		swap(index[arr[i][1]] , index[arr[ind][1]]);
		minheapify(arr, ind, n , index);
	}
}

void build_min_heap(int a[][2], int n , int index[]) {
	int i;
	for (i = n / 2; i >= 1; i--) {
	minheapify(a, i, n , index);
	}
}

pp extract_min(int arr[][2] , int &n , int index[] ) {

pp z;
z.first = arr[1][0];
z.second = arr[1][1];

	swap(arr[1][0], arr[n][0]);
	swap(arr[1][1] , arr[n][1]);
	swap(index[arr[1][1]] , index[arr[n][1]]);
	n--;
	minheapify(arr, 1 , n, index);
	
return z;	
}		
void decrease_key(int arr[][2] , int i , int k, int index[]) {

	if (arr[i][0] <= k)
		return ;
        arr[i][0] = k;
       // printf("-->%d ", arr[i][0]);
	while (i > 1 && arr[i/2][0] > arr[i][0]) {
			swap(arr[i][0], arr[i/2][0]);
			swap(arr[i][1] , arr[i/2][1]);
			swap(index[arr[i][1]] , index[arr[i/2][1]]);
			i = i / 2;
			}
}		
			
