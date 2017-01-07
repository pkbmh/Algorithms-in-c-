#include <bits/stdc++.h>
using namespace std;

int cost(vector<int>&a , int i,  int n) {
	
	if(n == i)
	return 0;
	
	int c = INT_MAX;
	int tmp;

	for(int k = i; k < n; k++) {
		tmp = cost(a , i , k)+cost(a , k+1 , n)+a[i-1]*a[k]*a[n];
		if(tmp < c)
		c = tmp;
	}
return c;
}
int main()
{	
	int n,i;
	scanf("%d", &n);
	vector<int>a;
	a.resize(n);
	for(i = 0; i < n; i++)
	scanf("%d", &a[i]);
	
	int ans = cost(a , 1 , n-1);
	
	printf("%d\n", ans);

return 0;
}
