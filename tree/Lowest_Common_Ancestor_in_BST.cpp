#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

bool is_path(tree_node *root , int n , vector < int > &path) {
    if(root == NULL)
        return false;
    path.push_back(root->data);
    if(root->data == n)
        return true;
    bool res = is_path(root->left, n , path);
    if(res)
        return true;
    res = is_path(root->right , n , path);
    if(res)
        return true;

    path.pop_back();
    return false;
}
int lowest_common_ancestor(tree_node *root , int n1 , int n2) {
    vector < int > path1,path2;

    bool p1 = is_path(root , n1 , path1);
    if(!p1)
        return -1;
    bool p2 = is_path(root , n2 , path2);
    if(!p2)
        return -1;

    for(int i = 0; ( i < path1.size() && i < path2.size() ); i++)
        if(path1[i] != path2[i])
            return path1[i-1];

    return -1;
}
int main()
{
    tree_node *root = NULL;
    int t,n;
    cout << "Enter number of node" << endl;
    cin >> n;

    cout << "Enter value of each node " << endl;

    while(n--){
        cin >> t;
        root = insert_node_in_tree(root , t);
    }

    cout << "level order traversal of tree is" << endl;
    levelorder(root);
    cout << endl;

    cout << "Enter 1st node and 2nd node to find LCA" << endl;
    int n1,n2;
    cin >> n1 >> n2;


    int lca = lowest_common_ancestor(root , n1 , n2);

    if(lca == -1)
        cout << "either n1 or n2 not in tree" << endl;
    else
        cout << "LCA IS " << lca << endl;


return 0;
}
