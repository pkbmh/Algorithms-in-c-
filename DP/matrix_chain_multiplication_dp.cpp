#include <bits/stdc++.h>
using namespace std;
int seq[100][100];

void printseq(int i , int j) {
	if(i == j) {
		cout << "A" << i;
		return;
	}
	cout << "(";
	printseq(i , seq[i][j]);
	printseq(seq[i][j]+1 , j);
	cout << ")";
}
int main()
{	
	int n,i,j,k,tmp;
	scanf("%d", &n);
	vector<int>a;
	a.resize(n);
	for(i = 0; i < n; i++)
	scanf("%d", &a[i]);
	
	int tab[n][n];
	
	for(i = 0; i < n; i++)
		tab[i][i] = 0;
	
	for(int l = 2; l < n; l++) {	
		
		for(i = 1; i <= n-l+1; i++) {
			j = i+l-1;
		
			tab[i][j] = INT_MAX;			
			for(k = i; k <= j-1; k++) {
					tmp = tab[i][k]+tab[k+1][j]+a[i-1]*a[k]*a[j];
					
						if(tmp < tab[i][j]) {
							tab[i][j] = tmp;
							seq[i][j] = k;
						}
			}
		}
	}

	printf("%d\n", tab[1][n-1]);
	printseq(1 , n-1);
	cout<<endl;

return 0;
}
