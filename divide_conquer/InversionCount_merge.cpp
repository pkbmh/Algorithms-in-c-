#include <cstdio>
#include <iostream>
#define max 200009
using namespace std;
long long merge(long int a[], long int left[],long int right[],int l,int r) {
	int i = 0,j=0;
	long long  count = 0;
	while(i < l || j < r) {
		if(i == l) {
			a[i+j] = right[j];
			j++;
		}
		else if(j == r) {
			a[i+j] = left[i];
			i++;
		}
		else if(left[i] <= right[j]) {
			a[i+j] = left[i];
			i++;
		}
		else {
			a[i+j] = right[j];
			count += l-i;
			j++;
		}
		}
return count;
}
long long unsigned  mergesort(long int a[], int h) {
	if(h < 1)
	return 0;
	int i,j;
	long long x;
	long long y;
	long long z;
	int mid = (h + 1) / 2;
	long int left[mid];
	long int right[h - mid + 1];
	
	for(i = 0; i < mid; i++)
	left[i] = a[i];

	for(i = h-mid,j = h; j >= mid; i--,j--)
	right[i] = a[j];

	x = mergesort(left ,mid-1);
	y = mergesort(right ,h-mid);
	z = merge(a,left,right,mid, h-mid+1);
return (x+y+z);
}
int main()
{
	int t;
	long int a[max];
	long long unsigned ans;
	scanf("%d", &t);
	while(t--) {
		int n;
	int i;
	scanf("%d", &n);
	//long int a[n];
		for (i = 0; i < n; i++)
		scanf("%ld", &a[i]);

		ans = mergesort(a,n-1);
			printf("%llu\n", ans);
	}
return 0;
}


