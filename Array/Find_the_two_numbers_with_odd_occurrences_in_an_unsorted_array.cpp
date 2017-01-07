#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

void find_odd_occurrences(int arr[] , int n) {
    int XOR = 0;
    int x = 0 , y = 0;
    int set_bit_no;

    for(int i = 0; i < n; i++)
        XOR = XOR ^ arr[i];

    set_bit_no = (XOR)&~(XOR-1);

    for(int i = 0; i < n; i++) {
        if(set_bit_no & arr[i])
            x ^= arr[i];
        else
            y ^= arr[i];
    }
    cout << x << " " << y << endl;
}
int main()
{
    int arr[] = {4, 2, 4, 5, 2, 3, 3, 1};;
    int n = ARRAY_SIZE(arr);

    find_odd_occurrences(arr , n);

return 0;
}
