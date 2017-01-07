#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

tree_node *get_min(tree_node *ptr) {
    while(ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}
tree_node *find_successor(tree_node *root , tree_node *tmp) {
    if(tmp->right != NULL)
        return get_min(tmp->right);

    tree_node *ptr,*pptr;
    ptr = root;

    while(ptr != NULL && ptr != tmp && tmp->data < ptr->data) {

        pptr = ptr;

        if(ptr->data > tmp->data)
            ptr = ptr->left;
        else if(ptr->data < tmp->data)
            ptr = ptr->right;
    }
    return pptr;
}
int main()
{
    tree_node *root = NULL;
    int n;

    root = insert_node_in_tree(root, 20);
    root = insert_node_in_tree(root, 8);
    root = insert_node_in_tree(root, 22);
    root = insert_node_in_tree(root, 4);
    root = insert_node_in_tree(root, 12);
    root = insert_node_in_tree(root, 10);
    root = insert_node_in_tree(root, 14);

   tree_node *temp = root->left->right->right;


    cout << "inorder traversal of tree is " << endl;
    inorder(root);
    cout << endl;

   tree_node *tmp =  find_successor(root , temp);
   cout<< "\n inorder successor of  "  << temp->data << " is " << tmp->data << endl;

return 0;
}

