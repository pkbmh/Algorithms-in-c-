#include <bits/stdc++.h>
using namespace std;

int count_binary_string(int n) {
 int e1 = 1;
 int e0 = 1;

 for(int i = 2; i <= n; i++)
 {
     int t = e0;
     e0 = e1 + e0;
     e1 = t;
   //  cout << i << " : " << (e1+e0) << endl;
 }
 return (e1+e0);
}
int main()
{
    int n;
    cout << "Enter n" << endl;
    cin >> n;

    int total_bs = count_binary_string(n);
    cout << "Total possible binary string of length " << n << " without consecutive 1's is = " << total_bs << endl;
return 0;
}
