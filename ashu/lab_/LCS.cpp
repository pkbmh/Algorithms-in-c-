#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int LCS(char s1[], char s2[]) {
	int x, y, i, j;
	x = strlen(s1);
	y = strlen(s2);
	int a[x+1][y+1];
	
	for(i = 0; i <= x; ++i) {
		for(j = 0; j <= y; ++j) {
			if(i == 0 || j == 0)
				a[i][j] = 0;
			else
				if(s1[i-1] == s2[j-1])
					a[i][j] = a[i-1][j-1] + 1;
				else
					a[i][j] = max(a[i][j-1], a[i-1][j]);
		}
	}
	cout << a[x][y] << endl;
	
	int index = a[x][y];
	char b[index+1];
	b[index] = '\0';
	i = x;
	j = y;
	while(i > 0 && j > 0) {
		if(s1[i-1] == s2[j-1]) {
			b[index-1] = s1[i-1];
			i--;
			j--;
			index--;
		}
		else
			if(a[i-1][j] > a[i][j-1])
				i--;
			else 
				j--;
	}
	cout << b << endl; 
}

int main() {
	char s1[10001], s2[10001];
	cin >> s1;
	cin >> s2;
	LCS(s1, s2);
	return 0;
}
