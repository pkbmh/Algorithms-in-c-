#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdio>
#define ll long long int
#define max 100005

using namespace std;


int main()
{
	ll arr[max], n, i, c, j;

	cin >> n;

	for (i = 0 ; i < n; i++) {
		cin >> arr[i];
	}

	for (i = 1; i < n; i++) {
		c = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > c) {
				arr[j+1] = arr[j];
				arr[j] = c;
			} else {
				break;
			}
		}

	}

	for (i = 0 ; i < n; i++) {
		cout << arr[i] << "\t";
	}

	return 0;

}
