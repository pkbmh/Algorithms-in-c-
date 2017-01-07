#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

int count_node(tree_node *root) {
    if(root == NULL)
        return 0;
    return 1 + count_node(root->left) + count_node(root->right);
}
int find_kth_smallest(tree_node *root , int k) {
    if(root == NULL)
        return INT_MAX;

    int l = count_node(root->left);
    //int r = count_node(root->right);

    if(l == k)
        return root->data;
    else if(k < l)
        return find_kth_smallest(root->left ,  k);
    else
        return find_kth_smallest(root->right , k-l-1);
}
int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Enter number of node " << endl;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root  , rand()%100);

    cout << "Created tree is (inorder)" << endl;
    inorder(root);
    cout << endl;

    cout << "Enter k for find k'th smallest element" << endl;
    int k;
    cin >> k;

    int kth = find_kth_smallest(root , k-1);
    cout << k<< "'th smallest element in tree is " << kth << endl;

return 0;
}
