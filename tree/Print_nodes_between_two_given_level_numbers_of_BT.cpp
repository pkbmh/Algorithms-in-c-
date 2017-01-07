#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

void print_node_between_level(tree_node *root , int low , int high) {
    queue <pair < tree_node * , int > > qu;
    qu.push(make_pair(root , 0));
    pair < tree_node * , int > tmp;

    while(!qu.empty()) {
        tmp = qu.front();
        qu.pop();

        if(tmp.second >= low && tmp.second <= high)
            cout << (tmp.first)->data << " ";

        if((tmp.first)->left != NULL)
            qu.push(make_pair((tmp.first)->left , (tmp.second)+1));
         if((tmp.first)->right != NULL)
            qu.push(make_pair((tmp.first)->right , (tmp.second)+1));

    }

}
void print_node_between_level_rec(tree_node *root, int low , int  high) {
    int h = height(root);
    low += 1;
    high += 1;
    for(int i = 1; i <= h; i++)
        if(i >= low && i <= high)
            print_at_height(root , i);

}
int main()
{
    tree_node *root = NULL;
    cout << "Enter number of node " << endl;
    int n;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "Created tree is (levelorder)" << endl;
    levelorder(root);

    cout << "Enter high and low level " << endl;
    int high,low;
    cin >> low >> high;

    //print_node_between_level(root, low , high);
     print_node_between_level_rec(root, low , high);
return 0;
}
