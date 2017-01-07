#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
template <class x> void swaper(x &a , x &b) { x t = a; a = b; b = t;}
void segregate(int arr[] , int n) {
    int l,h;
    l = 0;
    h = n-1;

    while(l < h) {
        if(arr[l] % 2 == 0)
            l++;
        else {
            swaper(arr[l] , arr[h]);
            h--;
        }
    }
}
int main()
{
   // int arr[] =  {12, 34, 45, 9, 8, 90, 3};
    int arr[] = { 2, 4, 5, 9, 3, 8, 6 };
    int n = ARRAY_SIZE(arr);

    segregate(arr , n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

return 0;
}
