#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

tree_node *create_manually()
{
  tree_node *root = create_newnode(50);
  root->left        = create_newnode(7);
  root->right       = create_newnode(2);
  root->left->left  = create_newnode(3);
  root->left->right = create_newnode(5);
  root->right->left  = create_newnode(1);
  root->right->right = create_newnode(30);

  return root;
}
void increment(tree_node *root , int diff) {
    if(root->left != NULL){
        root->left->data += diff;
        increment(root->left ,diff);
    }

    else if(root->right != NULL){
        root->right->data += diff;
        increment(root->right , diff);
    }
}
void convert_into_children_sum(tree_node *root) {
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return;

    convert_into_children_sum(root->left);
    convert_into_children_sum(root->right);

    int l , r;
    l = r = 0;
    if(root->left != NULL)
        l = root->left->data;
    if(root->right != NULL)
        r = root->right->data;

    int diff = (l + r) - root->data;

    if(diff > 0)
        root->data += diff;
    if(diff < 0)
        increment(root , -diff);
}
int main()
{
    tree_node *root = create_manually();
    cout << "tree is (levelorder)" << endl;
    levelorder(root);
    cout << endl;

    convert_into_children_sum(root);
    cout << "Converted tree is(levelorder)" << endl;
    levelorder(root);
    cout << endl;

return 0;
}
