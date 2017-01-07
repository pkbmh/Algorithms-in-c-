#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

#define ll long long int
#define FOR(i , n) for(i = 1; i <= n; i++)
#define maximum(a , b) (a > b) ? a : b
#define minimum(a , b) (a > b) ? b : a
#define tr(it , c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

vector<int>p;
vector<int>benifit;

void Cut_benifit(int n) {
	benifit[0] = 0;
	int i ,j;
		
	FOR(i , n) {
		int max = 0;
		FOR(j , i){
			max = maximum(max  , p[j] + benifit[i-j]);
		}
 
		benifit[i] = max;
			//	cout<<i<<" "<<benifit[i]<<endl;
	}
}
	
int main()
{
	int i;
	int n;
	printf("Enter length of road\n");
	scanf("%d", &n);
	p.resize(n+1);
	benifit.resize(n+1);
	printf("Enter price of road piece 1 to length\n");
	
	FOR(i , n) {
		scanf("%d", &p[i]);	
	}
	Cut_benifit(n);	
	//FOR(i , n) {
		//cout<<benifit[i]<<" ";
	//}
	printf("\nMaximum benifit of this road  is = %d\n", benifit[n]);
	scanf("%d", &n);
	//getchar();
return 0;
}