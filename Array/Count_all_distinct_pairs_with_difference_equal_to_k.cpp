#include <bits/stdc++.h>
using namespace std;

int count_all_distinct(int arr[] , int n , int k) {
    sort(arr ,arr+n);

    int l , r,c;
    c = 0;
    l = 0;
    r = 1;

    while(r < n) {

        if(arr[r]-arr[l] == k){
            c++;
            cout << arr[r] << " " << arr[l] << endl;
            l++;
            r++;
        }
        else if(arr[r]-arr[l] > k)
            l++;
        else
            r++;
    }
    return c;
}
int main()
{
    int n;
    cout << "Enter size of array " << endl;
    cin >> n;

    int arr[n];

    cout << "Enter array " << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int  k = 3;
    int all_pair = count_all_distinct(arr , n , k);
    cout << "All pair is " << all_pair << endl;

return 0;
}
