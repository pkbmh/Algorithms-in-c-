#include <bits/stdc++.h>
#include "BST.cpp"
using namespace std;

void construct_tree(tree_node **root , int arr[] , int l , int h) {
    if(l > h)
        return;

    int mid = (l + h) / 2;

    *root = create_newnode(arr[mid]);

    construct_tree(&(*root)->left , arr , l , mid-1);
    construct_tree(&(*root)->right , arr , mid+1 , h);

}
tree_node *construct_balance_BST(int arr[]  , int n) {
    tree_node *root = NULL;

    construct_tree(&root , arr , 0 , n-1);

    return root;
}
int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Number of element in array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array " << endl;
    for(int i= 0; i < n; i++)
        cin >> arr[i];

    root = construct_balance_BST(arr , n);

    cout << "tree is (inorder traversal )" << endl;
    inorder(root);


    int h = height(root);
    cout << "\n height is " << h-1 << endl;
return 0;
}
