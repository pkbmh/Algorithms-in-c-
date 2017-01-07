#include <bits/stdc++.h>
using namespace std;

void find_four_element(int arr[] , int n , bool visited[] , int selected  ,int index ,  int cur_sum , int sum) {
    if(index >= n && selected > 3)
        return ;
   if(cur_sum + arr[index] == sum && selected == 3) {
    visited[index] = true;
    for(int i = 0; i < n; i++)
        if(visited[i])
            cout << arr[i] << " ";
    cout << endl;

    visited[index] = false;
   }

   if(cur_sum + arr[index] < sum ) {
        visited[index] = true;
        find_four_element(arr , n , visited , selected+1 , index+1 , cur_sum+arr[index] , sum);
        visited[index] = false;
    }
   if(index+1 < n && cur_sum + arr[index+1] <= sum) {
        find_four_element(arr , n , visited , selected , index+1 , cur_sum , sum);
   }
}
int main()
{
    int n;
    cout << "Enter number of element in array" << endl;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
       // cin >> arr[i];
        arr[i] = i+1;
    }
    sort(arr , arr+n);

    bool visited[n];
    memset(visited , false , sizeof(visited));

    int sum;
    cout << "Enter sum " << endl;
    cin >> sum;

    find_four_element(arr , n , visited , 0 , 0 , 0 , sum);


return 0;
}
