#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

tree_node *create_manually()
{

    tree_node *root = create_newnode(1);
    root->left = create_newnode(2);
    root->right = create_newnode(3);
    root->left->left = create_newnode(4);
    root->right->left = create_newnode(5);
    root->right->right = create_newnode(6);
    root->right->left->right = create_newnode(7);
    root->right->right->right = create_newnode(8);
    root->right->left->right->left = create_newnode(9);
    root->right->right->right->right = create_newnode(10);

    return root;
}

void deepest_left_leaf(tree_node *root , int depth , bool is_left , pair < tree_node * , int > &res) {
    if(root == NULL)
        return ;
    if(root->left == NULL && root->right == NULL) {
        if(is_left && depth > res.second) {
            res.first = root;
            res.second = depth;
        }
        return;
    }
    deepest_left_leaf(root->left , depth+1 , true , res);
    deepest_left_leaf(root->right , depth+1 , false , res);
}
int main()
{
    tree_node *root = create_manually();
    cout << "tree is (levelorder) " << endl;
    levelorder(root);
    cout << endl;

    pair < tree_node * , int > res;
    deepest_left_leaf(root , 0 , false , res);
    cout << (res.first)->data << endl;

return 0;
}
