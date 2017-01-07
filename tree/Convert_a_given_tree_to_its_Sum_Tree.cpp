#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

tree_node *create_manually()
{
  tree_node *root = NULL;
  root = create_newnode(10);
  root->left = create_newnode(-2);
  root->right = create_newnode(6);
  root->left->left = create_newnode(8);
  root->left->right = create_newnode(-4);
  root->right->left = create_newnode(7);
  root->right->right = create_newnode(5);

  return root;
}

void convert_into_sum_tree(tree_node *root) {
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL) {
        root->data = 0;
        return;
    }
    int cs = 0;

    if(root->left != NULL)
        root->data = root->left->data;
    if(root->right != NULL)
        root->data += root->right->data;

    convert_into_sum_tree(root->left);
    convert_into_sum_tree(root->right);

    if(root->left != NULL)
        cs += root->left->data;
    if(root->right != NULL)
        cs += root->right->data;

        root->data +=  cs;

}

int convert_into_sum_tree1(tree_node *root) {
    if(root == NULL)
        return 0;
    int old_val = root->data;

    root->data  = convert_into_sum_tree1(root->left) + convert_into_sum_tree1(root->right);

    return (root->data + old_val);
}
int main()
{
    tree_node *root = create_manually();
    cout << "tree is (levelorder)" << endl;
    levelorder(root);
    cout << endl;

    convert_into_sum_tree(root);
    cout << "converted sum tree is " << endl;
    inorder(root);

return 0;
}
