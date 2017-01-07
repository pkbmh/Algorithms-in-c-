#include <stdio.h>
#define max 100000

void merge(int arr[], int low, int high, int mid)
{
	int tmp[high - low + 1];
	int i;
	int j;
	int k;
	i = low;
	j = mid + 1;
	k = 0;
	while ((i <= mid) || (j <= high)) {
		if (i > mid) {
			tmp[k] = arr[j];
			j++;
		}
		else if (j > high) {
			tmp[k] = arr[i];
			i++;
		}
		else if(arr[i] <= arr[j]) {
			tmp[k] = arr[i];
			i++;
		}
		else if(arr[i] >= arr[j]) {
			tmp[k] = arr[j];
			j++;
		}
		k++;
	}
	for (i = low,k=0;i <= high;i++,k++) {
		arr[i] = tmp[k];
	}
}

void mergesort(int arr[], int low, int high)
{
	int mid;
	mid = (low + high) /  2;
	if(low < high) {
		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		merge(arr, low, high, mid);
	}
}

int main()
{
	int arr[max];
	int n;
	int i;
	int j;
	
	i = 0;
	
	while (scanf("%d", &n) != EOF) {
		arr[i] = n;
		i++;
	}
	
	mergesort(arr, 0, i - 1);
	
	for (j = 0; j < i; j++) {
		printf("%d ", arr[j]);
	}
	
	return 0;
}




