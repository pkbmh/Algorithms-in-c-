#include <bits/stdc++.h>
using namespace std;

void print_pair(int arr[] , int n , int x) {
    int i,j;
    i = 0;
    j = n-1;
    int f,s;
    int diff = INT_MAX;

    while(i < j) {
        if(arr[i] + arr[j] == x){
            cout << arr[i] << " " << arr[j] << endl;
            return;
        }
        //diff = (diff > abs((arr[i]+arr[j])-x) ) ? abs((arr[i]+arr[j])-x) : diff;
        if(diff > abs(arr[i]+arr[j]-x)) {
            diff = abs((arr[i]+arr[j])-x);
            f = i;
            s = j;
        }
        if(arr[i]+arr[j] < x)
            i++;
        else
            j--;
    }
    cout << arr[f] << " " << arr[s] << endl;
}
int main()
{
    int n;
    cout << "Enter size of array " << endl;
    cin >> n;

    int  arr[n];

    cout << "Enter array" << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter X " << endl;
    int x;
    cin >> x;

    print_pair(arr , n , x);

return 0;
}
