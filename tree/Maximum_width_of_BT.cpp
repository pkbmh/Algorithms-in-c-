#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

tree_node *create_manually()
{

  tree_node *root = create_newnode(1);
  root->left        = create_newnode(2);
  root->right       = create_newnode(3);
  root->left->left  = create_newnode(4);
  root->left->right = create_newnode(5);
  root->right->right = create_newnode(8);
  root->right->right->left  = create_newnode(6);
  root->right->right->right  = create_newnode(7);

  return root;
}

int node_at_level(tree_node *root , int level , int &c) {
    if(root == NULL)
        return 0;
    if(level == 1)
        c++;
    node_at_level(root->left , level-1 , c);
    node_at_level(root->right , level-1 , c);

}
void width_at_level(tree_node *root) {
    int h = height(root);
    int c;
    for(int i = 1; i <= h; i++) {
        c = 0;
        node_at_level(root , i , c);
        cout << "At level " << i << " width is  " << c << endl;
    }
}
int main()
{
    tree_node *root = create_manually();
    cout << "tree is " << endl;
    levelorder(root);

    width_at_level(root);

return 0;
}
