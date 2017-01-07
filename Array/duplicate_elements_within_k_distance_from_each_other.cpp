#include <bits/stdc++.h>
using namespace std;

bool duplicate_at_k_distance(int arr[] , int n , int k , int max) {
    int pre_index[max];

    memset(pre_index , -1 , sizeof(pre_index));

    for(int i = 0; i < n; i++) {

        if(pre_index[arr[i]] == -1)
            pre_index[arr[i]] = i;
        else {
            if(abs(pre_index[arr[i]] - i) == k)
                return true;
        }
    }

    /*for(int i = 0; i < max; i++)
        cout << pre_index[i] << " i " << i << endl;*/
    return false;
}

int main()
{
    int n;
    cout << "Enter size of array " << endl;
    cin >> n;

    int arr[n];
    int max = INT_MIN;

    cout << "Enter array " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(max < arr[i])
            max = arr[i];
    }

    int k;
    cout << "Enter k " << endl;
    cin >> k;
    bool result = duplicate_at_k_distance(arr , n , k , max);
    if(result)
        cout << "True" << endl;
    else
        cout << "False " << endl;


return 0;
}
