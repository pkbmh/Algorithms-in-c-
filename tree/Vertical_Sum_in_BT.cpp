#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;
typedef pair < int , int > pii;


void find_distance(tree_node *root , vector < pii > &distance , int d) {
    if(root == NULL)
        return;
    distance.push_back(make_pair(d , root->data));
    //cout << root->data << " " << d << endl;
    find_distance(root->left , distance , d-1);
    find_distance(root->right , distance , d+1);

}
void vertical_sum(tree_node *root) {
    vector < pii > distance;
    find_distance(root , distance , 0);

    sort(distance.begin(), distance.end());
    int sum = distance[0].second;
    int d = distance[0].first;
    int line = 1;

    for(int i = 1; i < distance.size(); i++) {
        if(distance[i].first != d) {
            cout << "line " << line << " sum = " << sum << endl;
            d = distance[i].first;
            sum = distance[i].second;
            line++;
        }
        else
            sum += distance[i].second;
    }
    cout << "line " << line << " sum = " << sum << endl;
}
int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Enter number of node " << endl;
    cin >> n;
    while(n--)
        root = insert_node_in_tree(root , t);

    cout << "tree is levelorder " << endl;
    levelorder(root);

    vertical_sum(root);

return 0;
}
