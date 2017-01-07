/*Given an unsorted array, trim the array such that twice of minimum is greater than maximum in the trimmed array.
 Elements should be removed either end of the array.
*/
#include <bits/stdc++.h>
using namespace std;

int remove_minimum_element(int arr[] , int n) {
    int longest_start = -1;
    int longest_end  = 0;

    for(int start = 0; start < n; start++) {
        int min INT_MAX;
        int max = INT_MIN;

        for(int end = start+1; end < n; end++) {
            int val = arr[end];
            if(val < min) min = val;
            if(val > max) max = val;

            if(2 * min >= max)
                break;

            if(end-start > longest_end-longest_start || longest_start == -1) {
                longest_start = start;
                longest_end = end;
            }
        }
    }

    return (n-(longest_end-start+1));

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

    int min_remove = remove_minimum_element(arr , n);
    cout << "Minimum element remove " << min_remove << endl;

return 0;
}
