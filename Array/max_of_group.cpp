#include <bits/stdc++.h>
using namespace std;

int print_max_of_group(int arr[] , int n , int k) {

}
int main()
{
    int n;
    cout << "Enter number of element in array " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter array " << endl;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int k = 3;

    print_max_of_group(arr , n , k);

return 0;
}
