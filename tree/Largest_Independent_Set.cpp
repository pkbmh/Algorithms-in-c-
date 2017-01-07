/*
Given a Binary Tree, find size of the Largest Independent Set(LIS) in it.
A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset
*/
// DP solution is introduce a variable to check weather this node is
//visited or not if visited then return the lis of this node

#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

int LIS(tree_node *root) {
    if(root == NULL)
        return 0;

    int include ,exclude;
    include = 1;
    exclude = 0;

    if(root->left != NULL)
        include += LIS(root->left->left) + LIS(root->left->right);
    if(root->right != NULL)
        include += LIS(root->right->left) + LIS(root->right->right);

    exclude += LIS(root->left) + LIS(root->right);

    return max(include , exclude);
}
tree_node *create_manually() {

    tree_node *root         =  create_newnode(20);
    root->left                = create_newnode(8);
    root->left->left          = create_newnode(4);
    root->left->right         = create_newnode(12);
    root->left->right->left   = create_newnode(10);
    root->left->right->right  = create_newnode(14);
    root->right               = create_newnode(22);
    root->right->right        = create_newnode(25);

    return root;
}
int main()
{
    tree_node *root = NULL;
    root = create_manually();

    cout << "tree is levelorder" << endl;
    levelorder(root);

    int lis = LIS(root);
    cout << "Largest independent Set is " << lis << endl;

return 0;
}
