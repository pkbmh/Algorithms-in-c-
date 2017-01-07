/*Given Inorder Traversal of a Special Binary Tree in which key of every node is greater than keys in left and right children.
Examples:
Input: inorder[] = {5, 10, 40, 30, 28}
Output: root of following tree
         40
       /   \
      10     30
     /         \
    5          28

*/
#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

int search_max(int in[] , int l , int h) {
    int mi = l;
    for(int i = l+1; i <= h; i++)
        if(in[mi] < in[i])
            mi = i;

    return mi;
}
tree_node *construct_tree(int in[] , int l , int h) {
    if(l > h)
        return NULL;
    if(l == h)
        return create_newnode(in[h]);

    int mi = search_max(in , l , h);
    int m = in[mi];

    tree_node *root = create_newnode(in[mi]);

    root->left = construct_tree(in , l , mi-1);
    root->right = construct_tree(in , mi+1 , h);

    return root;
}
int main()
{
    int n;
    cout << "Enter number of element in tree " << endl;
    cin >> n;

    int in[n];
    cout << "Enter inorder traversal " << endl;
    for(int i = 0; i < n; i++)
        cin >> in[i];

    tree_node *root = construct_tree(in , 0 , n-1);
    cout << "constructed tree is " << endl;
    levelorder(root);
return 0;
}
