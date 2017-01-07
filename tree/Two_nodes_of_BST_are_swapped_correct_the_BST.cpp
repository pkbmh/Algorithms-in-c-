#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

tree_node *create_manually() {
    tree_node *root = create_newnode(6);
    root->left        = create_newnode(10);
    root->right       = create_newnode(2);
    root->left->left  = create_newnode(1);
    root->left->right = create_newnode(3);
    root->right->right = create_newnode(12);
    root->right->left = create_newnode(7);

    return root;
}

void correct_bst(tree_node *root) {
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return;

    if(root->data >= root->left->data && root->data <= root->right->data) {
        correct_bst(root->left);
        correct_bst(root->right);
    }
    else  {
        if(root->data >= root->right->data && root->data <= root->left->data)
        {
            int tmp = root->right->data;
            root->right->data = root->left->data;
            root->left->data = tmp;
        }
        else if(root->data <= root->left->data && root->left->data <= root->right->data) {
            int tmp = root->left->data;
            root->left->data = root->data;
            root->data = tmp;
        }
        else {
            int tmp = root->right->data;
            root->right->data = root->data;
            root->data = tmp;
        }
        return;
    }
}
int main()
{
    tree_node *root = create_manually();
    cout << "Created tree is (inorder)" << endl;
    levelorder(root);
    cout << endl;

    correct_bst(root);

    cout << "After correction bst is (inorder)" << endl;
    inorder(root);

return 0;
}
