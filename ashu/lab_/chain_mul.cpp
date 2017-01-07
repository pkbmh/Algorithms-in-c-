#include <iostream>
#include<cstdio>
#include<climits>
using namespace std;
int s[100][100];
 
void chain(int p[], int n)
{
	int m[n][n]; 
	int i, j, k, t, q;
	for (i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) 
			m[i][j] = 0;
	} 
	
	for(t = 2; t < n; t++)  {
		for(i = 1; i <= n-t+1; i++) {
			j = i+t-1;
			m[i][j] = INT_MAX;
			for(k = i; k <= j-1; k++) {
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	for (i = 1; i < n; i++) {
		for(j = 1; j < n; j++) { 
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}
	cout << m[1][n-1] << endl;
}

void seq(int i, int j) {
	if(i == j)
		cout <<  "A" << i ;
	else {
		cout <<"(";
		seq(i, s[i][j]);
		seq((s[i][j]+1), j);
		cout <<")";
	}
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	
	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	chain(arr, n); 
	
	for (int i = 1; i < n; i++) {
		for(int j = 1; j < n; j++) { 
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
	
	seq(1, n-1);
	cout << endl;
	return 0;
}
