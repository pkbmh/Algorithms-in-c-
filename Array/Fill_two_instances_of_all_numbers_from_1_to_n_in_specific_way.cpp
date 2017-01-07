#include <bits/stdc++.h>
using namespace std;

bool can_fill(int arr[] , int i , int  val) {
    if(arr[i] == -1 && arr[i+val+1] == -1)
        return true;
    return false;
}

/*bool fill_array(int arr[] , int n , int cur)  {
    if(cur > n)
        return true;
    for(int i = 0; i < 2*n; i++) {
        if(can_fill(arr , i , cur)) {
            arr[i] = cur;
            arr[cur+i+1] = cur;
            if(fill_array(arr , n ,cur+1))
                return true;
            arr[i] = -1;
            arr[cur+i+1] = -1;
        }
    }
    return false;
}*/

bool fill_array(int arr[] , int cur , int n) {
    if(cur == 0)
        return true;

    for(int i = 0; i < (2*n); i++) {

        if(can_fill(arr , i , cur)) {
            arr[i] = arr[i+cur+1] = cur;

            if(fill_array(arr , cur-1 , n))
                return true;

            arr[i] = arr[i+cur+1] = -1;
        }
    }
}
int main()
{
    int n;
    cout << "Enter n" << endl;
    cin >> n;

    int arr[2*n];
    for(int i = 0; i < 2 * n; i++)
        arr[i] = -1;

    bool res = fill_array(arr , n , n);
    if(res)
        for(int i = 0; i < 2*n; i++)
            cout << arr[i] << " ";
    else
        cout << "Not possible" << endl;

return 0;
}
