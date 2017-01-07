#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

void print_left_boundary(tree_node *root) {
    if(root == NULL)
        return;

    if(root->left != NULL) {
        cout << root->data << " ";
        print_left_boundary(root->left);
    }
    else if(root->right != NULL) {
        cout << root->data << " ";
        print_left_boundary(root->right);
    }
}
void print_right_boundary(tree_node *root) {
    if(root == NULL)
        return;

    if(root->right != NULL) {
        cout << root->data << " ";
        print_left_boundary(root->right);
    }
    else if(root->left != NULL) {
        cout << root->data << " ";
        print_left_boundary(root->left);
    }
}

void print_leaf(tree_node *root) {
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
        cout << root->data << " ";

    else {
    print_leaf(root->left);
    print_leaf(root->right);
    }
}

void print_boundary_node(tree_node *root) {
    if(root == NULL)
        return;

    cout << root->data << " ";

    print_left_boundary(root->left);
    print_leaf(root);
    print_right_boundary(root->right);

}
int main()
{
    int n;
    cout << "Enter number of node" << endl;
    cin >> n;

    tree_node *root = NULL;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "Tree is (levelorder)" << endl;
    levelorder(root);

    cout << "Boundary node is " << endl;
    print_boundary_node(root);

return 0;
}
