#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

tree_node *construct_tree_util(int pre[] , int &pre_index , int data , int min , int max , int n) {
    if(pre_index >= n)
        return NULL;

    tree_node *root = NULL;

    if(data > min && data < max) {
        root = create_newnode(data);
        pre_index = pre_index + 1;
        if(pre_index < n) {
            root->left = construct_tree_util(pre , pre_index , pre[pre_index] , min , data , n);
            root->right = construct_tree_util(pre , pre_index , pre[pre_index] , data , max , n);

        }
    }
    return root;
}
tree_node *construct_tree(int pre[] , int n) {
    int pre_index = 0;
    tree_node *root = construct_tree_util(pre , pre_index , pre[0] , INT_MIN , INT_MAX , n);

    return root;
}
int main()
{
    int n;
    cout << "Enter number of node " << endl;
    cin >> n;
    int pre[n];

    cout << "Enter preorder " << endl;

    for(int i = 0; i < n; i++)
        cin >> pre[i];

    tree_node *root = construct_tree(pre , n);
    cout << "Constructed tree is (levelorder)" << endl;
    levelorder(root);
    cout << endl;

return 0;
}
