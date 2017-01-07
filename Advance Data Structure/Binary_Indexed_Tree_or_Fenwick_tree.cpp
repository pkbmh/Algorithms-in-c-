#include <bits/stdc++.h>
using namespace std;

void update_BIT(int BIT[] , int val , int index , int n) {
    index += 1;
    while(index <= n) {
        BIT[index] += val;
        index += (index&(-index));
    }

}
int *create_BIT(int arr[] , int n) {
    int *BIT = new int[n+1];
    //int BIT[n+1];

    for(int i = 1; i <= n; i++)
        BIT[i] = 0;

    for(int i = 0; i < n; i++)
        update_BIT(BIT , arr[i] , i , n);

return BIT;
}

int get_sum(int BIT[] , int k) {
    k += 1;
    int sum = 0;
    while(k > 0) {
        sum += BIT[k];
        k -= (k&(-k));
    }
    return sum;
}
int main()
{
    int n,i, index , val,k;
    //cout << "Enter number of element in array " << endl;
    //cin >> n;

    int arr[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    n = sizeof(arr) / sizeof(arr[0]);
   // cout << n << endl;
    cout << "Enter array " << endl;

    int *BIT = create_BIT(arr , n);

   /* for(i = 1; i <= n; i++)
        cout << BIT[i] << " ";
    cout << endl;
    */
    cout << "Enter k to get sum (0..k)" << endl;
    cin >> k;

    int sum = get_sum(BIT , k);
    cout << "Sum of array [0..k] is "  << sum << endl;



    cout << "Enter index and value for update at this index" << endl;
    cin >> index >> val;
    int diff = val - arr[index];
    arr[index] = val;

    update_BIT(BIT ,diff , index , n);

    cout << "Enter k to get sum [0..k]" << endl;
    cin >> k;
    sum = get_sum(BIT , k);
    cout << "Sum of array [0..k] is "  << sum << endl;

return 0;
}
