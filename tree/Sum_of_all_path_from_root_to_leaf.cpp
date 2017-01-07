#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

void all_path_sum(tree_node *root , int &sum , int cur_sum) {
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL) {
        sum += cur_sum + root->data;
        return;
    }
    cur_sum = cur_sum + root->data;

    all_path_sum(root->left , sum , cur_sum);
    all_path_sum(root->right , sum , cur_sum);

}
int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Enter number of node we'll generate complete BT" << endl;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%10);

    cout << "level order traversal of tree " << endl;
    levelorder(root);

    int h = height(root);
    cout << "\n height of tree is " << h-1 << endl;
    int sum = 0;
    all_path_sum(root , sum , 0);

    cout << " all path sum is = " << sum;

return 0;
}
