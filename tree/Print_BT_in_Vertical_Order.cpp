#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;
typedef pair < int , int > pii;

void assing_distance(tree_node *root , vector < pii > &vertical_node , int d) {
    if(root == NULL)
        return;
    vertical_node.push_back(make_pair(d , root->data));

    assing_distance(root->left , vertical_node , d-1);
    assing_distance(root->right , vertical_node , d+1);
}
void vertical_order(tree_node *root) {
        vector < pii > vertical_node;

        assing_distance(root , vertical_node , 0);
        sort(vertical_node.begin() , vertical_node.end());

        int d = vertical_node[0].first;
        for(int i = 0; i < vertical_node.size(); i++) {
            if(d != vertical_node[i].first) {
                d = vertical_node[i].first;
                cout << endl;
            }
            cout << vertical_node[i].second << " ";
        }
        cout << endl;
}
int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Enter number of node " << endl;
    cin >> n;
    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "tree is levelorder" << endl;
    levelorder(root);

    cout << "tree is vertical order" << endl;
    vertical_order(root);

return 0;
}
