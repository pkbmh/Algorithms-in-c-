/* Write a program that converts a given tree to its Double tree.
To create Double tree of the given tree, create a new duplicate for each node,
and insert the duplicate as the left child of the original node.
*/

#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

void double_tree(tree_node *root){
    if(root == NULL)
        return;
    tree_node *tmp = create_newnode(root->data);
    if(root->left == NULL)
        root->left = tmp;

    else {
        tree_node *ptr = root->left;
        root->left = tmp;
        tmp->left = ptr;
    }

    double_tree(tmp->left);
    double_tree(root->right);

}
tree_node *create_manually(){
    tree_node *root = create_newnode(1);
    root->left        = create_newnode(2);
    root->right       = create_newnode(3);
    root->left->left  = create_newnode(4);
    root->left->right = create_newnode(5);

    return root;
}
int main()
{
    tree_node *root = create_manually();
    cout << "tree is (levelorder)" << endl;
    levelorder(root);

    double_tree(root);
    cout << "Doubled tree is (levelorder)" << endl;
    levelorder(root);


return 0;
}
