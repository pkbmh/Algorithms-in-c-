#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

void print_node_not_sibling(tree_node *root) {
    if(root == NULL)
        return;

    if(root->left != NULL && root->right != NULL) {
        print_node_not_sibling(root->left);
        print_node_not_sibling(root->right);
    }
    else if(root->left == NULL && root->right != NULL) {
        cout << root->right->data << " ";
        print_node_not_sibling(root->right);
    }
    else if(root->right == NULL && root->left != NULL) {
        cout << root->left->data << " ";
        print_node_not_sibling(root->left);
    }

}
int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Enter number of node " << endl;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);



    cout << "Tree is (levelorder) " << endl;
    levelorder(root);
    cout << endl;


    print_node_not_sibling(root);

return 0;
}

