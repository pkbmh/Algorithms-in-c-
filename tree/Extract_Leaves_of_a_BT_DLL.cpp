#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

void print_list(tree_node *head) {
    while(head != NULL) {
        cout << head->data << "->";
        head = head->right;
    }
    cout << "NULL" << endl;
}
tree_node *extract_leaves(tree_node *root , tree_node **head) {
    if(root == NULL)
        return NULL;
    if(root->left == NULL && root->right == NULL) {
        root->right = (*head);
        if((*head) != NULL)
           (*head)->left = root;

           (*head) = root;
           return NULL;
    }
    root->left = extract_leaves(root->left , head);
    root->right = extract_leaves(root->right , head);


    return root;
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

    tree_node *head = NULL;
    extract_leaves(root , &head);

    cout << "List is ";
    print_list(head);
    cout << endl;

    cout << "Modified tree is (levelorder)" << endl;
    levelorder(root);
    cout << endl;


return 0;
}
