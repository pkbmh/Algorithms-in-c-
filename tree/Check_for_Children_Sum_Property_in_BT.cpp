#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

tree_node *create_manually(){

  tree_node *root  = create_newnode(10);
  root->left         = create_newnode(8);
  root->right        = create_newnode(2);
  root->left->left   = create_newnode(3);
  root->left->right  = create_newnode(5);
  root->right->right = create_newnode(2);
    return root;
}

bool check_children_sum(tree_node *root) {
    if(root == NULL || (root->left == NULL && root->right == NULL) )
        return true;
    int child_sum = 0;
    if(root->left != NULL)
        child_sum += root->left->data;
    if(root->right != NULL)
        child_sum += root->right->data;


    if(child_sum == root->data) {
        return ( check_children_sum(root->left) && check_children_sum(root->right) );
    }
    else
        return false;
}
int main()
{
    tree_node *root = create_manually();
    cout << "tree is (levelorder)" << endl;
    levelorder(root);
    cout << endl;

    bool res = check_children_sum(root);
    if(res)
        cout << "Tree is satisfying children sum property " << endl;
    else
        cout << "Tree not satisfy children sum property " << endl;
return 0;
}
