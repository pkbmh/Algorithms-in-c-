/* 
Input:
n = 3  
pairs[] = {1->3, 2->6, 4->5}  // 1 is partner of 3 and so on
arr[] = {3, 5, 6, 4, 1, 2}

Output: 2
We can get {3, 1, 5, 4, 6, 2} by swapping 5 & 6, and 6 & 1

3
1 3 2 6 4 5
3 5 6 4 1 2
*/

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define TR(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define PII pair<int,int>
#define VI vector<int>
#define VF vector<float>
#define VD vector<double>
#define VPII vector<PII>
template<class T> void swaper(T &a , T &b) {T c = a; a = b; b = c;}


int Minimum_Swap_Util(VI arr , VI pairs , int n , VI index , int cur_i) {
	if(cur_i >= (2*n)-1)
		return 0;

	if(pairs[arr[cur_i]] == arr[cur_i+1])
		return Minimum_Swap_Util(arr , pairs , n , index , cur_i+2);

	int pone = pairs[cur_i];
	int ipone = index[pone];
	swaper(arr[cur_i+1] , arr[ipone]);
	int MS1 = Minimum_Swap_Util(arr , pairs , n , index , cur_i+2);
	swaper(arr[cur_i+1] , arr[ipone]);


	int ptwo = pairs[cur_i+1];
	int iptwo = index[ptwo];
	swaper(arr[cur_i] , arr[iptwo]);
	int MS2 = Minimum_Swap_Util(arr , pairs , n , index , cur_i+2);
	swaper(arr[cur_i] , arr[iptwo]);

	return 1 + min(MS1 , MS2);


}
int Minimum_Swap(VI arr , VI pairs , int n) {
	VI index(2*n+1);
	for(int i = 0; i < 2*n; i++)
		index[arr[i]] = i;

	return Minimum_Swap_Util(arr , pairs , n  , index , 0);

}
int main()
{
	int f,s,n,av;
	cin >> n;

	VI arr;
	VI pairs(2*n+1);

	for(int i = 0; i < n; i++) cin >> f >> s,
		pairs[f] = s , pairs[s] = f;

	for(int i = 0; i < 2*n; i++) cin >> av , arr.PB(av);

	cout << Minimum_Swap(arr , pairs , n) << endl;

return 0;
}