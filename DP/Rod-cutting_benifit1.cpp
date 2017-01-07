#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int
#define FOR(i , n) for(i = 1; i <= n; i++)
#define maximum(a , b) (a > b) ? a : b
#define minimum(a , b) (a > b) ? b : a
#define tr(it , c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)


typedef struct info{
	ll p;
	ll l;
}a;
vector<a>r;

bool compair(a a1 , a a2) {
	if(a1.l > a2.l)
	return false;
	else return true;
}
vector<ll>benifit;
int n;

void Cut_benifit(ll l) {
	//cout<<i<<" "<<l<<" "<<n;
	for(int i = 1; i <= l; i++) {
		ll max  = 0;
		for(int j = 1; j <= i; j++) {
			if(r[j].l <= i) {
				max  = maximum(max , r[j].p+benifit[i-r[j].l]);
			}
		}
		benifit[i] = max;
	}
				
}
	
int main()
{
	int i;
	ll l;
	scanf("%d", &n);
	scanf("%lld" , &l);

	r.resize(n+1);
	benifit.clear();
	benifit.resize(l+1);
	benifit[0] = 0;
	ll t1,t2;
	FOR(i , n) {
		scanf("%lld%lld", &t1 , &t2);
		r[i].p = t2;
		r[i].l = t1;
	}
	sort(r.begin() , r.end() , compair);
	
	Cut_benifit(l);	
	//FOR(i , n) {
		//cout<<benifit[i]<<" ";
	//}
	printf("%lld\n", benifit[l]);
	//scanf("%d", &n);
	//getchar();
return 0;
}
