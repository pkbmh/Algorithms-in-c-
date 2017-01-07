#include <bits/stdc++.h>
using namespace std;

int find_first_repeating(int arr[] , int n) {
    map < int , bool > *mymap = new map < int , bool >;
    int min_index;

    for(int i = n-1; i >= 0; i--) {
        if( (*mymap)[arr[i]] == NULL) {
            (*mymap)[arr[i]] = true;
        }
        else {
            min_index = i;
        }
    }
    return arr[min_index];
}
int main()
{
    int n;
    cout << "Enter size of array " << endl;
    cin >> n;

    int arr[n];

    cout << "Enter array " << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int first_repeating = find_first_repeating(arr , n);
    cout << "First repeating element is " << first_repeating << endl;

return 0;
}
