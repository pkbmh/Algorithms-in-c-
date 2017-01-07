#include <bits/stdc++.h>
using namespace std;

int replace_index(int binary_array[] , int n) {
    int max1,cur,pre,index,pre_index;
    cur = 0;
    pre = 0;
    index = 0;
    pre_index = -1;
    max1 = INT_MIN;

    for(int i = 0; i < n; i++) {
        if(binary_array[i] == 0) {
            if(max1 < pre + cur) {
                max1 = pre + cur;
                if(pre_index == -1)
                    pre_index = i;
                else
                    pre_index = index;
            }

            index  = i;
            pre = cur;
            cur = 0;
        }
        else
            cur += 1;
    }
    return index;
}
int main()
{
    int n;
    cout << "Enter number of element in binary array " << endl;
    cin >> n;

    int binary_arr[n];
    cout << "Enter array" << endl;
    for(int i = 0; i < n; i++)
        cin >> binary_arr[i];

    int index = replace_index(binary_arr , n);
    cout << "Index for replace 0 to 1 is " << index;

return 0;
}
