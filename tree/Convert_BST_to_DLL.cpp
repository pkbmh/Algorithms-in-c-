#include <bits/stdc++.h>
#include "BST.cpp";

using namespace std;

void convert_to_DLL(tree_node *root , tree_node **start , tree_node **end) {
    if(root == NULL)
        return;

    if(root->left != NULL)
        convert_to_DLL(root->left , start , end);

    root->left = *end;

    if(*end != NULL)
        (*end)->right = root;
    else
        *start = root;

    *end = root;

    if(root->right != NULL)
        convert_to_DLL(root->right , start , end);

}
void print_list(tree_node *root)
{
    if(root == NULL)
        return;
    cout << root->data << " ";
    print_list(root->right);
}
int main()
{
    tree_node *root = NULL;

    int n;
    cout << "Enter number of node " << endl;
    cin >> n;

    cout << "Enter value of each node " << endl;
    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "Level order traverse of tree" << endl;
    levelorder(root);

    tree_node *start , *end;
    start = end = NULL;

    convert_to_DLL(root , &start , &end);
    cout << "converted list is " << endl;
    print_list(start);

return 0;
}
