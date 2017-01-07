#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of digits in array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter all digits" << endl;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int pi[n+1];
    pi[0] = 1;
    pi[1] = 1;


    for(int i = 1; i < n; i++) {
        int c1 = arr[i-1];
        int c2 = arr[i];

        pi[i+1] = 0;

        if(c2 == 0) {
            pi[i+1] = pi[i-1];
            continue;
        }
        if(c1 != 0 || c2 != 0)
            pi[i+1] = pi[i];

        if(c2 != 0 && (c1 == 1 || (c1 == 2 && c2 <= 6)))
            pi[i+1] += pi[i-1];

       // cout << " i " << i << " "<< pi[i+1] << endl;
    }
    cout << "possible interpretation is = " << pi[n] << endl;

return 0;
}
