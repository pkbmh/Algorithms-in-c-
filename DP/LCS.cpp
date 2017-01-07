#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define max(a,b) (a > b) ? a : b

int LCS(char a[],char b[], int la,int lb) {
	if(la == 0 || lb == 0)
	return 0;
	if(a[la] == b[lb])
	return 1+LCS(a,b,la-1,lb-1);
	else
	return max(LCS(a,b,la,lb-1) , LCS(a,b,la-1,lb));
}
int main()
{
	int i;
	char a[1000];
	char b[1000];
	cout<<"Enter string to find LCS"<<endl;
	cin>>a>>b;
	int la = strlen(a);
	int lb = strlen(b);
	printf("Longest Common Subsequence is  = %d\n", LCS(a,b,la,lb));

return 0;
}
