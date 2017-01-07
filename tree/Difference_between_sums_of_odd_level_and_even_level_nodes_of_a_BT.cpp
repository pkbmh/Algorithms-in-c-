#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

tree_node *create_manually()
{
    tree_node *root = create_newnode(5);
    root->left = create_newnode(2);
    root->right = create_newnode(6);
    root->left->left  = create_newnode(1);
    root->left->right = create_newnode(4);
    root->left->right->left = create_newnode(3);
    root->right->right = create_newnode(8);
    root->right->right->right = create_newnode(9);
    root->right->right->left = create_newnode(7);

    return root;
}
int difference_between(tree_node *root) {
    if(root == NULL)
        return 0;
    return root->data - difference_between(root->left) - difference_between(root->right);
}
int main()
{
    int n;
    tree_node *root = NULL;
    root = create_manually();

     cout << "Created tree  is (levelorder)" << endl;
    levelorder(root);

    int diff = difference_between(root);
    cout << "Difference between odd level and even level sum is " << endl;
    cout << diff << endl;
return 0;
}
