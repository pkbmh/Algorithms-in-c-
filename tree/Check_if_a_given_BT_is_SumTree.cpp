#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;


int is_sum_cal(tree_node *root) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return root->data;

    int l = is_sum_cal(root->left);
    int r = is_sum_cal(root->right);

    if(root->data == (l + r))
        return (2 * root->data);
    else
        return -1;
}
bool is_sum_tree(tree_node *root) {
    if(root == NULL)
        return true;
    int left = is_sum_cal(root->left);
    int right = is_sum_cal(root->right);

   // cout << "l " << left << " r " << right << endl;
    if(root->data == (left+right))
        return true;

    return false;
}
tree_node *create_manually()
{
    tree_node *root  = create_newnode(28);
    root->left         = create_newnode(10);
    root->right        = create_newnode(4);
    root->left->left   = create_newnode(4);
    root->left->right  = create_newnode(6);
    root->right->right = create_newnode(4);

    return root;
}
int main()
{
    tree_node *root = create_manually();
    cout << "tree is (levelorder)" << endl;
    levelorder(root);

    bool res = is_sum_tree(root);
    if(res)
        cout << "Yes !! given tree is sum_tree " << endl;
    else
        cout << "No tree is not sum_tree" << endl;

return 0;
}
