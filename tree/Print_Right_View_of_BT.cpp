/*
The Right view contains all nodes that are last nodes in their levels.
A simple solution is to do level order traversal and print the last node in every level.
*/

#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;
typedef pair < int , int > pii;

void print_right_view(tree_node *root , int level , int &max_level) {
    if(root == NULL)
        return;

    if(max_level < level){
        cout << root->data << " ";
        max_level = level;
    }

    print_right_view(root->right , level+1 , max_level);
    print_right_view(root->left , level+1 , max_level);
}
int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Enter number of node " << endl;
    cin >> n;
    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "tree is levelorder" << endl;
    levelorder(root);

    int max_level = 0;
    print_right_view(root , 1 , max_level);
return 0;
}

