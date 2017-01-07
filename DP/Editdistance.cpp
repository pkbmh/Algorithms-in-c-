#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	string str1 = "SUNDAYSDSDCAASECB";
	
	string str2 =  "SATUREUICKLSDCAASCDAY";
	
	int n = str1.length();
	int m = str2.length();

	int ed[n+1][m+1];

	for(int i  = 0 ; i <= n; i++)
		ed[i][0] = i;

	for(int i = 0 ; i <= m; i++)
		ed[0][i] = i;

	int c;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j  <= m; j++) {

			c = (str1[i-1] == str2[j-1]) ? 0 : 1;
			int a1 = ed[i-1][j-1];
			int a2 = ed[i][j-1];
			int a3 = ed[i-1][j];

			ed[i][j] = min(a1 , min(a2,a3)) + c;
			//T(m, n) = T(m-1, n-1) + T(m, n-1) + T(m-1, n) + C
		}
	}

	cout << ed[n][m] << endl;
return 0;
}