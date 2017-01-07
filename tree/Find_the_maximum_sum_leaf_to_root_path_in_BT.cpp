#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

void maximum_sum_root_to_leaf(tree_node *root , tree_node **leaf , int &sum , int cur_sum) {
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL) {
        cur_sum += root->data;
        if(cur_sum > sum){
            sum = cur_sum;
            *leaf = root;
        }
    }

    maximum_sum_root_to_leaf(root->left , leaf , sum , cur_sum + root->data);
    maximum_sum_root_to_leaf(root->right , leaf , sum , cur_sum + root->data);
}
int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Enter number of node " << endl;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root, rand()%100);

    cout << "Created tree is levelorder" << endl;
    levelorder(root);

    tree_node *leaf;
    int sum = 0;

    maximum_sum_root_to_leaf(root , &leaf , sum , 0);
    cout << "path sum is " << sum << endl;

    cout << "leaf is " <<leaf->data << endl;

return 0;
}
