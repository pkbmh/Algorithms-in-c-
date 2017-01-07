#include <bits/stdc++.h>
using namespace std;
#define FOR(i , n) for(i = 0; i < n; i++)
#define tr(it , c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define PB push_back
#define max_val 100000
#define bucket_size 10
/*typedef struct node {
	int value;
	struct node *next;
}node;
*/

vector<float>tmp;

void swap1(float *a , float *b) {
	float t = *a;
	*a = *b;
	*b = t;
}
int partition (int l, int h)
{
	int x = tmp[h]; // pivot
	int i = (l - 1); // Index of smaller element
	for (int j = l; j <= h- 1; j++)
	{
	if (tmp[j] < x)
	{
	i++; // increment index of smaller element
	swap1(&tmp[i], &tmp[j]); // Swap current element with index
	}
}
swap1(&tmp[i+1], &tmp[h]);
return (i + 1);
}
void quickSort(int l, int h)
{
	if(l >= h)
	return; 
	int p = partition(l, h); 
	quickSort(l, p - 1);
	quickSort(p + 1, h);
	 
	
}
int main(){
	
	int i;
	float t;
	unsigned long long int n;
	int index;
	scanf("%lld", &n);
	FOR(i , n) 
		tmp.PB(rand()%1000);
	
	cout<<"Initial array is "<<endl;
	FOR(i , n)
		cout<<tmp[i]<<" ";
	
	cout<<"\nFinal array is "<<endl;
	quickSort(0 , n-1);
	
	FOR(i , n)
		cout<<tmp[i]<<" ";
	
	cout<<endl;
return 0;
}
