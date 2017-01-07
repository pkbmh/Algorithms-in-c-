#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

int closest_leaf_down(tree_node *root) {
    if(root == NULL)
        return INT_MAX;
    if(root->left == NULL && root->right == NULL)
        return 0;

    return 1 + min(closest_leaf_down(root->left) , closest_leaf_down(root->right));
}
int closest_leaf(tree_node *root , int k , vector < tree_node * > &ancestor , int index) {
    if(root == NULL)
        return INT_MAX;
    if(root->data == k) {

        int res = closest_leaf_down(root);

        for(int i = index-1 ; i >= 0; i--) {
            res = min(res , index - i + closest_leaf_down(ancestor[i]));
        }

        return res;
    }
    ancestor[index] = root;

    int l = closest_leaf(root->left , k , ancestor , index+1);
    int r = closest_leaf(root->right , k  , ancestor , index+1);

    return min(l , r);
}
int main()
{
    int n;
    tree_node *root = NULL;
    cout << "Enter number of node " << endl;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "Created tree is(levelorder)" << endl;
    levelorder(root);
    cout << endl;

    int k;
    cout << "Enter key " << endl;
    cin >> k;

    vector < tree_node * > ancestor(1000);

    int dis = closest_leaf(root , k , ancestor , 0);
    cout << "distance of closest leaf is  " << dis << endl;

return 0;
}
