#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"
using namespace std;

tree_node *find_next_right(tree_node *root , int k) {
    queue < pair < tree_node *  , int > > qu;
    qu.push(make_pair(root , 0));
    pair < tree_node * , int > tmp;

    while(!qu.empty()) {
        tmp = qu.front();
        qu.pop();

        if((tmp.first)->data == k) {
            if(qu.empty())
                return NULL;
            int kl = tmp.second;

            tmp = qu.front();
            qu.pop();
            if(tmp.second == kl)
                return (tmp.first);
            else
                return NULL;
        }
        if((tmp.first)->left != NULL)
            qu.push(make_pair((tmp.first)->left , (tmp.second) + 1));
        if((tmp.first)->right != NULL)
            qu.push(make_pair((tmp.first)->right , (tmp.second) + 1));
    }

}
int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Enter number of node " << endl;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root  , rand()%100);

    cout << "Created tree is (levelorder)" << endl;
    levelorder(root);
    cout << endl;

    cout << "Enter key for find next right" << endl;
    int k;
    cin >> k;

    tree_node *next_right = find_next_right(root , k);

    if(next_right != NULL)
        cout << "Next right node is " << next_right->data << endl;
    else
        cout << "NULL" << endl;

return 0;
}

