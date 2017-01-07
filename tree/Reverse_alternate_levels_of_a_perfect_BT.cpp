#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

void assign_level(tree_node *root , stack < int > &node_data , int level) {
    if(root == NULL)
        return;

    assign_level(root->left , node_data , level+1);

    if(level % 2 != 0)
        root->data = node_data.top() , node_data.pop();

    assign_level(root->right , node_data , level+1);

}

void store_alternate_level(tree_node *root , stack < int > &node_data , int level) {
    if(root == NULL)
        return;

    store_alternate_level(root->left , node_data , level+1);

    if(level % 2 != 0)
        node_data.push(root->data);

    store_alternate_level(root->right , node_data , level+1);
}

void reverse_alternate_level(tree_node *root) {
    if(root == NULL)
        return;

    stack < int > node_data;

    store_alternate_level(root , node_data , 0);

    assign_level(root , node_data , 0);
}
int main()
{
    tree_node *root = NULL;
    int t,n,total_node;
    cout << "Enter level of tree we'll generate random tree" << endl;
    cin >> n;
    total_node = pow(2 , n)-1;

    srand(time(NULL));

    while(total_node--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "level order traverse of initial tree is " << endl;
    levelorder(root);

    reverse_alternate_level(root);

    cout << "After reverse alternate level (level order traversal )" << endl;
    levelorder(root);

return 0;
}
