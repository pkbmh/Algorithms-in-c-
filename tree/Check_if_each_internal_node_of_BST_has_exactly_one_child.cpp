/*
Given Preorder traversal of a BST, check if each non-leaf node has only one child.
 Assume that the BST contains unique entries.
*/
#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

bool check_one_child(int pre[] , int n) {
    int next;
    int last;

    for(int i = 0; i < n-1; i++) {
        next = pre[i+1]-pre[i];
        last = pre[n-1] - pre[i];

        if(next * last < 0)
            return false;
    }
    return true;

}
int main()
{
    cout << "Enter number of node " << endl;
    int n;
    cin >> n;

    int pre[n];

    for(int i = 0; i < n; i++)
        cin >> pre[i];

    bool res = check_one_child(pre , n);
    if(res)
        cout << "YES" << endl;
    else
        cout << "No" << endl;

return 0;
}
