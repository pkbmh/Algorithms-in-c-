/*
Given a binary tree in which each node element contains a number.
Find the maximum possible sum from one leaf node to another.
*/
#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"
using namespace std;

tree_node *create_manually()
{
    tree_node *root = create_newnode(-15);
    root->left = create_newnode(5);
    root->right = create_newnode(6);
    root->left->left = create_newnode(-8);
    root->left->right = create_newnode(1);
    root->left->left->left = create_newnode(2);
    root->left->left->right = create_newnode(6);
    root->right->left = create_newnode(3);
    root->right->right = create_newnode(9);
    root->right->right->right= create_newnode(0);
    root->right->right->right->left= create_newnode(4);
    root->right->right->right->right= create_newnode(-1);
    root->right->right->right->right->left= create_newnode(10);

    return root;
}

int max_path_sum(tree_node *root , int &path_sum) {
    if(root == NULL)
        return 0;

    int lps = max_path_sum(root->left , path_sum);
    int rps = max_path_sum(root->right , path_sum);

    int cur_sum = max((lps+rps+root->data) , max(lps , rps));

    if(cur_sum > path_sum)
        path_sum = cur_sum;

    return max(lps ,rps)+root->data;
}
int main()
{
    tree_node *root = create_manually();
    cout << "Created tree is (levelorder)" << endl;
    levelorder(root);
    cout << endl;

    int path_sum = 0;
    max_path_sum(root , path_sum);
    cout << "Maximum sum between two leaf is " << path_sum << endl;

}
