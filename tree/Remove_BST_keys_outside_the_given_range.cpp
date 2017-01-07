#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;


tree_node *delete_node_outside_range(tree_node *root , int min  , int max) {
    if(root == NULL)
        return root;


    root->left = delete_node_outside_range(root->left , min , max);
    root->right = delete_node_outside_range(root->right , min , max);


    if(root->data < min) {
        tree_node *tmp = root->right;
        delete root;
        return tmp;
    }
    else if(root->data > max) {
        tree_node *tmp = root->left;
        delete root;
        return tmp;
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
    cout << endl;

    int min , max;
    cout << "Enter range " << endl;
    cin >> min >> max;
    cout << endl;

    root = delete_node_outside_range(root , min , max);
    levelorder(root);
return 0;
}
