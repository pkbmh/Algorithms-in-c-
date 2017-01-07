#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

void convert_into_greater_sum(tree_node *root , int &sum) {
    if(root == NULL)
        return;

    convert_into_greater_sum(root->right , sum);
    sum = sum + root->data;
    root->data = sum - root->data;
    convert_into_greater_sum(root->left , sum);

}

int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Enter number of node " << endl;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%10);

    cout << "Initial tree is " << endl;
    levelorder(root);
    cout << endl;

    int sum = 0;
    convert_into_greater_sum(root , sum);

    cout << "Final tree is " << endl;
    levelorder(root);
    cout << endl;

return 0;
}
