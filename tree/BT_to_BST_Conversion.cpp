#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"
using namespace std;

void store_node(tree_node *root , vector < int >&node) {
    if(root == NULL)
        return;
    store_node(root->left , node);
    node.push_back(root->data);
    store_node(root->right , node);
}

void store_node_back(tree_node *root , vector < int > &node  , int &i) {
    if(root == NULL)
        return;
    store_node_back(root->left , node , i);
    root->data = node[i];
    i++;
    store_node_back(root->right , node , i);
}
void convert_into_BST(tree_node *root) {
    vector < int > node;

    store_node(root , node);

    sort(node.begin() , node.end());
    int i = 0;
    store_node_back(root , node , i);

}
int main()
{
    int n;
    tree_node *root = NULL;
    cout << "Enter number of node " << endl;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "Tree is (levelorder) " << endl;
    levelorder(root);


    convert_into_BST(root);
    cout << "Inorder traversal of converted BST" << endl;
    inorder(root);
    cout << endl;

return 0;
}
