#include <bits/stdc++.h>
using namespace std;

bool zero_sum_subarray(int arr[] , int n) {
    map < int , int > sum_map;

    int sum = 0;

    map < int ,  int >::iterator it;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum == 0 || arr[i] == 0 || sum_map.find(sum) != sum_map.end()) {
            it = sum_map.find(sum);
            cout <<"Zero sum subarray is from :: "  <<it->second+1 << " to  " << i << endl;
            return true;
        }
        sum_map.insert(make_pair(sum , i));
    }
    return false;
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

    bool res = zero_sum_subarray(arr , n);
    if(res)
        cout << "Yes zero sum sub-array present " << endl;
    else
        cout << "Zero sum sub-array not present" << endl;

return 0;
}
