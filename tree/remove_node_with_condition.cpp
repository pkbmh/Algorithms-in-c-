/*
Remove all nodes which don’t lie in any path with sum>= k
Given a binary tree, a complete path is defined as a path from root to a leaf.
The sum of all nodes on that path is defined as the sum of that path. Given a number K,
you have to remove (prune the tree) all nodes which don’t lie in any path with sum>=k.
Note: A node can be part of multiple paths. So we have to delete it only in case when all paths from it have sum less than K.

*/
#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

tree_node *delete_node_not_in_path(tree_node *root ,int &sum ,  int k) {
    if(root == NULL)
        return NULL;

    sum = sum + root->data;
    int lsum = sum;
    int rsum = sum;

    root->left = delete_node_not_in_path(root->left , lsum , k);
    root->right = delete_node_not_in_path(root->right , rsum , k);

    sum = max(lsum , rsum);

    if(sum < k) {
        free(root);
        root = NULL;
    }

    return root;
}

int main()
{
    tree_node *root = NULL;
    int n,t;
    cout << "Enter number of node" << endl;
    cin >> n;
    while(n--) {
        cin >> t;
        root = insert_node_in_tree(root , t);
    }
    cout << "level order traversal of tree " << endl;
    levelorder(root);
    int k;
    cout << "Enter K " << endl;
    cin >> k;
    cout << endl << endl;
    int sum = 0;
    root = delete_node_not_in_path(root ,sum , k);

    cout << "After deletion (level order traversal) is" << endl;
    levelorder(root);

return 0;
}
