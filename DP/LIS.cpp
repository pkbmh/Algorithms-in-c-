#include <iostream>
#include <cstdio>
#include <vector>
#define max(a,b) (a > b) ? a : b
using namespace std;
vector<int>ls;
int LS(vector<int>a , int n) {
	int j;
	int ret = 0;
	if(n < 1)
	return 0;
	if(n == 1)
	return 1;
	for(j = n-1; j >= 1; j--) {
		if(a[j] < a[n]){
		ret  = max(LS(a , j) , ret);
		}
	}
	return ret+1;
}

int main()
{
	int i;
	int n;
	cout<<"Enter number of element"<<endl;
	cin>>n;
	vector <int>a;
	a.resize(n+1);
	ls.resize(n+1);
	for(i = 1; i <= n; i++)
	cin>>a[i];

	cout<<"LIS = "<<LS(a,n)<<endl;

return 0;
}
