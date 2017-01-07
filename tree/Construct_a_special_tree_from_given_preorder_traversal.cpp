/*
Given an array ‘pre[]’ that represents Preorder traversal of a spacial binary tree where every node has either 0 or 2 children.
 One more array ‘preLN[]’ is given which has only two possible values ‘L’ and ‘N’. The value ‘L’ in ‘preLN[]’ indicates that
 the corresponding node in Binary Tree is a leaf node and value ‘N’ indicates that the corresponding node is non-leaf node.
 Example:
Input:  pre[] = {10, 30, 20, 5, 15},  preLN[] = {'N', 'N', 'L', 'L', 'L'}
Output: Root of following tree
          10
         /  \
        30   15
       /  \
      20   5
*/

#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

tree_node *construct_tree(vector < pair < int , char > > &pre_LN ,int &index  , int n) {
    if(index == n)
        return NULL;
    tree_node *tmp = create_newnode(pre_LN[index].first);

    if(pre_LN[index].second == 'N' || pre_LN[index].second == 'n') {
            index = index + 1;
        tmp->left = construct_tree(pre_LN , index , n);
        tmp->right = construct_tree(pre_LN , index , n);
    }
    else
        index = index + 1;
    return tmp;
}
int main()
{
    int n;
    cout << "Element in pre-oreder" << endl;
    cin >> n;

    vector < pair < int , char > > pre_LN;

    cout << "Enter data and type of each node " << endl;

    int t;
    char c;
    for(int i = 0; i < n; i++){
        cin >> t >> c;
        pre_LN.push_back(make_pair(t , c));
    }
    int index = 0;
    tree_node *root = construct_tree(pre_LN , index , n);
    cout << "Constructed tree is " << endl;
    levelorder(root);
    cout << endl;

return 0;
}

