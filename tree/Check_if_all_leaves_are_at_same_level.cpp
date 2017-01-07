/*

          12
        /    \
      5       7
    /          \
   3            1
  Leaves are at same level
          12
        /    \
      5       7
    /
   3
   Leaves are Not at same level
*/

#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

tree_node *create_manually(){

    tree_node *root = create_newnode(12);
    root->left = create_newnode(5);
    root->left->left = create_newnode(3);
    root->left->right = create_newnode(9);
    root->left->left->left = create_newnode(1);
    root->left->right->left = create_newnode(1);

     return root;
}

bool all_at_this(tree_node *root , int level , int cur) {
    if(root->left == NULL && root->right == NULL) {
        if(cur == level)
            return true;
        else
            return false;
    }
    bool l , r;
    l = r = true;
    if(root->left != NULL)
        l = all_at_this(root->left , level , cur+1);
    if(root->right != NULL)
        r = all_at_this(root->right , level , cur+1);

    return (l == true && r == true);

}
bool leaves_at_same_level(tree_node *root) {
    tree_node *ptr = root;
    int level = 0;

    while(ptr->left != NULL) {
        ptr = ptr->left;
        level++;
    }
    return all_at_this(root , level , 0);


}

int main()
{
    tree_node *root = create_manually();
    cout << "Enter number of node" << endl;


    bool res = leaves_at_same_level(root);
    if(res)
        cout << "Yes all leaves are at same level" << endl;
    else
        cout << "No all leaves are not at same level" << endl;

return 0;
}
