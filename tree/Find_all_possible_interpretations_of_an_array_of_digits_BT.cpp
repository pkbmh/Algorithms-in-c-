#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

tree_node *create_tree(int arr[] , int l , int h) {
    if(l > h)
        return NULL;
    if(l == h) {
        if(arr[l] == 0)
            return NULL;
        else
            return create_newnode(arr[l])
    }

    int c1 = arr[l];
    int c2 = arr[l+1];

    int digit = c1 * 10 + c2;

    if(digit > 0 && digit <= 26)

}
int main()
{
    int n;
    cout << "Enter number of digit" << endl;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    tree_node *root = create_tree(arr , 0 , n-1);

return 0;
}
