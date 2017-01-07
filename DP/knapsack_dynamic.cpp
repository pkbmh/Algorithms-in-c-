#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> v;
vector<int>w;
vector <vector <int> >table;
int n;
int max(int a , int b) {
return (a>b) ? a : b;
}
int ks(int c, int i){
	if(i > n-1) {
		table[c][i] = 0;
		return 0;
	}
	if(w[i] > c) {
		if(table[c][i+1] == -1) 
		table[c][i+1] =  ks(c, i+1);

		return table[c][i+1];
	}
	else{
		 if(table[c][i+1] == -1)
		 table[c][i+1] = ks(c, i+1);
	 
		 if(table[c-w[i]][i+1] == -1)
		 table[c-w[i]][i+1] = ks(c-w[i] , i+1); 
		
		return max(table[c][i+1] , (v[i] + table[c-w[i]][i+1]));
	}
}
int main(){
	
	scanf("%d", &n);
	v.resize(n);
	w.resize(n);
	
	int i,j;
	for(i = 0; i < n; i++){
		scanf("%d%d", &w[i],&v[i]);
	}
	
	int c;
	scanf("%d", &c);
	
	table.resize(c+1);
	
	for(i = 0; i <= c; i++)
		for(j = 0; j <= n; j++)
			table[i].push_back(-1);

	printf(" maximam benefit is = %d\n", ks(c, 0));

return 0;
}
