/*
Given a Binary Tree,
write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST).
If the complete Binary Tree is BST, then return the size of whole tree.
*/
#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

tree_node *create_manually() {


  tree_node *root = create_newnode(50);
  root->left        = create_newnode(10);
  root->right       = create_newnode(60);
  root->left->left  = create_newnode(5);
  root->left->right = create_newnode(20);
  root->right->left  = create_newnode(55);
  root->right->left->left  = create_newnode(45);
  root->right->right = create_newnode(70);
  root->right->right->left = create_newnode(65);
  root->right->right->right = create_newnode(80);

  return root;
}

int find_largest_bst(tree_node *root , int *min , int *max , int *max_size , bool *is_bst) {
    if(root == NULL){
        *is_bst = true;
        return 0;
    }

    int lmin = INT_MAX;

    bool left_flag = false;
    bool right_flag = false;

    int ls , rs;
    *min = INT_MAX;

    ls  = find_largest_bst(root->left , min , max ,max_size , is_bst);

    if (*is_bst == 1 && root->data > *max)
     left_flag = true;

    lmin = *min;
    *min = INT_MAX;
    rs = find_largest_bst(root->right, min, max, max_size, is_bst);

    if (*is_bst == 1 && root->data < *min)
     right_flag = true;

    if (lmin < *min)
     *min = lmin;
    if (root->data < *min) // For leaf nodes
     *min = root->data;
    if (root->data > *max)
     *max = root->data;

    /* If both left and right subtrees are BST. And left and right
     subtree properties hold for this node, then this tree is BST.
     So return the size of this tree */
    if(left_flag && right_flag)
    {
     if (ls + rs + 1 > *max_size)
         *max_size = ls + rs + 1;
     return ls + rs + 1;
    }
    else
    {
    //Since this subtree is not BST, set is_bst flag for parent calls
     *is_bst = 0;
     return 0;
    }


}
int largest_bst(tree_node *root) {
    int min = INT_MAX;
    int max = INT_MIN;
    int max_size = 0;
    bool is_bst = false;

    find_largest_bst(root , &min , &max , &max_size , &is_bst);

    return max_size;
}
int main()
{
    tree_node *root = create_manually();
    cout << "Created tree is " << endl;
    levelorder(root);
    cout << endl;

    int bst_size = largest_bst(root);
    cout << "size of largest bst is " << bst_size << endl;

return 0;
}
