#include <bits/stdc++.h>
using namespace std;

void largest_subarray(int arr[] , int n) {
    int sum_array[n];
    int sum = 0;
    int max_sum = INT_MIN;
    int min_sum = INT_MAX;

    for(int i = 0; i < n; i++) {
        sum += (arr[i] == 0) ? -1 : 1;
        sum_array[i] = sum;
        if(sum > max_sum)
            max_sum = sum;
        if(sum < min_sum)
            min_sum = sum;
    }
    /*for(int i = 0; i < n; i++)
        cout << sum_array[i] << " ";
    cout << endl;
    cout << max_sum << " " << min_sum  << endl;
    */

    int hash_tab[(max_sum - min_sum + 1)];
    for(int i = 0; i < (max_sum - min_sum - 1); i++)
        hash_tab[i] = -1;

    int start ,max_size,end_index;
    start = -1;
    for(int i = 0; i < n; i++) {
        if(sum_array[i] == 0) {
            max_size = i+1;
            start = 0;
        }
        if(hash_tab[sum_array[i]-min_sum] == -1)
            hash_tab[sum_array[i]-min_sum] = i;
        else {
            if((i-hash_tab[sum_array[i]-min_sum]) > max_size) {
                max_size = (i-hash_tab[sum_array[i]-min_sum]);
                start = hash_tab[sum_array[i]-min_sum]+1;
            }
        }
    }
    if(max_size == -1)
        cout << "No such array " << endl;
    else
        cout << start << " : " << (start + max_size -1)  << endl;
}
int main()
{
    int n;
    cout << "Enter element in array " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter array" << endl;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    largest_subarray(arr , n);

return 0;
}
