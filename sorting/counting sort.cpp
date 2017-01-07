#include <cstdio>
#include <vector>
#include <iostream>
#include <time.h>
#define ma 1000
#define ll long long int

using namespace std;

ll getMax(ll arr[], ll n)
{
    ll mx = arr[0];
    for (ll i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

ll count_sort(ll arr[ma], ll n, ll exp)
{
	ll i;
	ll count[ma];
	for (i = 0; i <= 9; i++) {
		count[i] = 0;
	}
	
	for (i = 0; i < n; i++) {
		count[(arr[i] / exp) % 10]++;
	}
	//cou
	for (i = 1; i <= 9; i++) {
		count[i]+= count[i - 1];
	//cout << count[i] << "\t";
	}
	cout << "\n";
	ll output[ma];
	
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	
	for (i = 0; i < n; i++) {
		arr[i] = output[i];
		cout << arr[i] << "\t";
	}
	
	cout << "\n";
	
}

void radix_sort(ll arr[ma], ll n)
{
 	int m = getMax(arr, n);
	for (ll exp = 1; m/exp > 0; exp *= 10)
        count_sort(arr, n, exp);
}

int main()
{
	ll n;
	ll arr[ma];
	
	scanf("%lld", &n);
	ll i;

	for (i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	radix_sort(arr, n);
	for (i = 0; i < n; i++) {
		//printf("%lld\t", arr[i]);
	}	
}
