#include <bits/stdc++.h>
using namespace std;

void print_inorder(int arr[] , int indx , int n) {
    //cout << arr[indx] << " ";
    if(indx < 0 || indx > n)
        return;

    int next = indx * 2;
    print_inorder(arr , next+1 , n);
    cout << arr[indx] << " ";
    print_inorder(arr , next+2 , n);

}
int main()
{
    int n;
    cout << "Enter number of element in array " << endl;
    cin >> n;
    int arr[n];

    cout << "enter array" << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "printing array in sorted order (inorder)" << endl;
    print_inorder(arr , 0 , n-1);
    cout << endl;
return 0;
}
