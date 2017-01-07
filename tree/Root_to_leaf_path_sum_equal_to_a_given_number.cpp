#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

bool find_path(tree_node *root , int cur , int sum , stack < int > &path) {
    if(root == NULL)
        return false;

    cur += root->data;
    if(cur == sum && root->left == NULL && root->right == NULL) {
        path.push(root->data);
        return true;
    }

    path.push(root->data);

    if( find_path(root->left , cur , sum , path) || find_path(root->right , cur , sum , path) ) {
        return true;
    }
    else {
        path.pop();
        return false;
    }

}
void print_path(stack < int > path) {
    if(path.empty())
        return;

    int t = path.top();
    path.pop();

    print_path(path);
    cout << t << " ";
}
int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Enter number of node " << endl;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "Tree is (level order) " << endl;
    levelorder(root);

    int sum;
    cout << "Enter number to find path" << endl;
    cin >> sum;

    stack < int > path;
    bool res = find_path(root , 0 , sum , path);
    if(res) {
        cout << "path exist in tree" << endl;
        cout << "path is = ";
        print_path(path);
        cout << endl;
    }
    else
        cout << "path not exit in tree for this number " << endl;

return 0;
}
