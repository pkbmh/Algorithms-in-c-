#include <bits/stdc++.h>
using namespace std;

vector < int > w;
//vector < bool > x;
int n;

void print_set(vector < bool > &x) {
	 int tmp = 0;
	cout << "[ ";
	for(int i = 0; i < n; i++) {
		cout << x[i] << " ";
		tmp += x[i]*w[i];
 
	}
		
	cout << "] " <<tmp<< endl;
	
}
// s = current sum , k = starting index , need = find subset for this value , tw = total weight of array 
// x is bitmask array 
void find_subset(int s , int k , int need , int tw , vector < bool > &x) {
 
	if(k >= n)
	return;
	
	x[k] = true;
	if(s + w[k] == need) {
		print_set(x); // function for print subset which is equal to need 
		x[k] = false; //backtrack 
		return;
	}
	
	else if(s + w[k] + w[k+1] <= need) 
	find_subset(s + w[k] , k + 1 , need ,  tw-w[k] , x);
	
	if(s + tw - w[k] >= need && s + w[k+1] <= need){
	x[k] = false;
	find_subset(s  , k+1 , need , tw-w[k] , x);
	}
	
	x[k] = false; //backtrack;
}
		
int main()
{	
	int tw = 0;
	cin >> n;
	vector < bool > x;
	w.resize(n);
	x.resize(n , false);

	for(int i = 0; i < n; i++) {
		cin >> w[i];
		tw += w[i];
	}
	int need;
	cin >> need;
	
	sort(w.begin() , w.end());
	cout << " ";
	for(int i = 0; i < n; i++)
		cout << w[i] << " ";
		
	cout << endl;
	
	find_subset(0 , 0 , need , tw , x);
	 
return 0;
}
