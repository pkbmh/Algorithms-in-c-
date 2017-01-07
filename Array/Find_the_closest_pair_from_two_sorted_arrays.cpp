#include <bits/stdc++.h>
using namespace std;

void print_closest_pair(int arr1[] , int size1 , int arr2[] , int size2 , int x) {
    int i,j;
    i = 0;
    j = size2-1;

    int diff = INT_MAX;
    int f , s;

    while(i < size1 && j >= 0) {
        if(arr1[i]+arr2[j] == x){
            cout << arr1[i] << " " << arr2[j] << endl;
            return;
        }
        if(diff > abs(arr1[i]+arr2[j]-x)) {
            diff = abs(arr1[i]+arr2[j]-x);
            f = i;
            s = j;
        }
        if(arr1[i]+arr2[j] < x)
            i++;
        else
            j--;
    }
    cout << arr1[f] << " " << arr2[s] << endl;
}
int main()
{
    int arr1[] =  {1, 4, 5, 7};
    int arr2[] = {10, 20, 30, 40};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    int x = 38;

    print_closest_pair(arr1, size1 , arr2 , size2 , x);
return 0;
}
