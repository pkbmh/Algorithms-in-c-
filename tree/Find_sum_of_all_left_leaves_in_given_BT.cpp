#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

void count_leaf_sum(tree_node *root , int &leaf_sum) {
    if(root == NULL)
        return ;
    if(root->left == NULL && root->right == NULL)
        leaf_sum = root->data;

    int lls = 0;
    count_leaf_sum(root->left , lls);
    int rls = 0;
    count_leaf_sum(root->right , rls);

    leaf_sum += lls + rls;

    //return leaf_sum;
}
int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Enter number of node " << endl;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "Created tree is (levelorder)" << endl;
    levelorder(root);
    cout << endl;

    int leaf_sum = 0;
    count_leaf_sum(root , leaf_sum);
    cout << "Sum of all leaf is = " << leaf_sum << endl;

return 0;
}
