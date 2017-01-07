#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

void print_unsorted(int arr[] , int n) {
    int s,e;
    for(s = 0; s < n-1; s++)
        if(arr[s+1] < arr[s])
            break;

    for(e = n-1; e > 0; e--)
        if(arr[e] < arr[e-1])
            break;

    int max,min;
    max = min = arr[s];

    for(int i = s+1; i <= e; i++) {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }

    for(int i = 0; i < s; i++) {
        if(arr[i] > min){
            s = i;
            break;
        }
    }
    for(int i = n-1; i >= e+1; i--) {
        if(arr[i] < max) {
            e = i;
            break;
        }
    }

    cout << s << " : " << e << endl;

}
int main()
{
    int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int n = ARRAY_SIZE(arr);

    print_unsorted(arr , n);

return 0;
}
