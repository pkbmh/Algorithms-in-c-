#include <bits/stdc++.h>
using namespace std;

bool is_identical_util(int a[] , int b[] , int n , int i1 , int i2 , int min , int max) {
    int j,k;

    for(j = i1; j < n; j++)
        if(a[j] > min && a[j] < max)
            break;

    for(k = 0; k < n; k++)
        if(b[k] > min && b[k] < max)
            break;

    if(j == n && k == n)
        return true;

    if( ((j == n) ^ (k == n)) || (a[j] != b[k]) )
        return false;

    return ( is_identical_util(a , b , n , j+1 , k+1 , a[j] , max) && is_identical_util(a , b , n , j+1 , k+1 , min , a[j]) );
}
bool is_identical(int a[] , int b[], int n) {

    return is_identical_util(a , b , n , 0 , 0 , INT_MIN , INT_MAX);

}
int main()
{
    int n;
    cout << "Enter number of node in tree " << endl;
    cin >> n;

    int a[n];
    int b[n];

    cout << "Enter array 1" << endl;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter array 2" << endl;
    for(int i = 0; i < n; i++)
        cin >> b[i];

    bool res = is_identical(a , b , n);
    if(res)
        cout << "both tree are identical " << endl;
    else
        cout << "Not identical " << endl;

return 0;
}
