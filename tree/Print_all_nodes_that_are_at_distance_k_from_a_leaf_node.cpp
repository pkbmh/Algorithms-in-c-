#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

void print_node(tree_node *root , int path[] , bool visited[] , int path_len , int k) {
    if(root == NULL)
        return;

    path[path_len] = root->data;
    visited[path_len] = false;
    path_len++;

    if(root->left == NULL && root->right == NULL && path_len-k-1 > 0 && visited[path_len-k-1] == false) {
        cout << path[path_len-k-1] << " ";
        visited[path_len] = true;
        return;
    }

    print_node(root->left , path , visited , path_len , k);
    print_node(root->right , path , visited , path_len , k);
}
void print_node_above_dis_leaf(tree_node *root , int k) {
    int h = height(root);
    int path[h+1];
    bool visited[h+1];
    memset(visited , false , sizeof(visited));
    print_node(root , path , visited , 0 , k);
}
int main()
{
    tree_node *root = NULL;
    int n;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);



    cout << "Tree is (levelorder) " << endl;
    levelorder(root);
    cout << endl;

    int k;
    cout << "Enter k " << endl;
    cin >> k;

    print_node_above_dis_leaf(root , k);

return 0;
}

