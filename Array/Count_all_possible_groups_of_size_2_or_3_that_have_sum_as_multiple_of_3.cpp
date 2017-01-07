#include <bits/stdc++.h>
using namespace std;

int count_group(int arr[] , int n) {
    int c[3];
    c[0] = c[1] = c[2] = 0;

    for(int i = 0; i < n; i++)
        c[arr[i]%3]++;

    //group of 2 element
    int total_group = (c[0] * (c[0]-1))>>1; // pick any two element from 0 remainder
    total_group += (c[1] * c[2]); // one element from 1 remainder and one element from 2 remainder

    // group of 3 element
    total_group += (c[0] * (c[0]-1) * (c[0]-2)) / 6; // all 3 from 0 remainder
    total_group += (c[0] * c[1] * c[2]); // one element from each group;
    total_group += (c[1] * (c[1]-1) * (c[1]-2)) / 6; // all 3 from 1 remainder
    total_group += (c[2] * (c[2]-1) * (c[2]-2)) / 6; // all 3 from 2 remainder

    return total_group;

}
int main()
{
    int n;
    cout << "Enter number of element in array" << endl;
    cin >> n;

    int arr[n];
    cout << "Enter array " << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int total_group = count_group(arr , n);
    cout << "possible groups of size 2 or 3 that have sum as multiple of 3 is = " << total_group << endl;

return 0;
}
