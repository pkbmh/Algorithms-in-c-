/* A pair-sum array for an array is the array that contains sum of all pairs in ordered form.
For example pair-sum array for arr[] = {6, 8, 3, 4} is {14, 9, 10, 11, 12, 7}.
In general, pair-sum array for arr[0..n-1] is {arr[0]+arr[1], arr[0]+arr[2], ……., arr[1]+arr[2], arr[1]+arr[3], ……., arr[2]+arr[3], arr[2]+arr[4], …., arr[n-2]+arr[n-1}.*/
#include <bits/stdc++.h>
using namespace std;

void construct_array(int pair_sum[] , int pair_n) {
    int n;

    for(n  = 1; n <= sqrt(2*pair_n)+1; n++)
        if((n * n + n) > (2 * pair_n))
           break;

    int arr[n];

    arr[0] = (pair_sum[0]+pair_sum[1]-pair_sum[n-1]) / 2;

    for(int i = 1; i < n; i++)
        arr[i] = pair_sum[i-1]-arr[0];

   cout << "Original array is " << endl;

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;


}
int main()
{
    int n;
    cout << "Enter size of pair sum array " << endl;
    cin >> n;

    int pair_sum[n];
    cout << "Enter pair sum array " << endl;

    for(int i = 0; i < n; i++)
        cin >> pair_sum[i];

     construct_array(pair_sum , n);


return 0;
}
