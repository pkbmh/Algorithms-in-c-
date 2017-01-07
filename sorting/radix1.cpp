#include <cstdio>
#include <vector>
#include <cstdlib>
#include <time.h>
#define ma 1000
#define ll int

using namespace std;

void func(ll arr[ma], ll n, ll exp, vector< int> arr1[ma])
{
	ll i;
	
	for (i = 0; i <= 9; i++) {
		arr1[i].clear();
	}
	ll c;
	ll k = 0, j;
	for (i = 0; i < n; i++) {
		c = (arr[i]/exp) % 10;
		if ((arr[i] / exp) == 0) {
			arr[k] = arr[i];
		k++;
			continue;
			//arr1[0].push_back(arr[i]);
		}
		arr1[c].push_back(arr[i]);
		//printf("")
	}


	for (i = 0; i <= 9; i++) {
		for (j = 0; j < arr1[i].size(); j++) {
			arr[k] = arr1[i][j];
			k++;
		}
	}

for (i = 0; i < n; i++) {
		printf("%d\t", arr[i]);
	}
	
	printf("\n");



	

	
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void radix_sort(ll arr[ma], ll n, vector<int> arr1[ma])
{
 	int m = getMax(arr, n);
	for (ll exp = 1; m/exp > 0; exp *= 10)
        func(arr, n, exp, arr1);
}

int main()
{
	ll n;
	ll arr[ma];
	vector<int> arr1[ma];
	time_t start, end;
	
	//printf("enter number of elements\n");
	scanf("%lld", &n);
	ll i;

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	start = clock();

	radix_sort(arr, n, arr1);
	end = clock();

	//double d = (start - end) / CLOCKS_PER_SEC;

	//printf("%lf", double);

	/*for (i = 0; i < n; i++) {
		printf("%d\t", arr[i]);
	}*/

	return 0;
}
	
	

