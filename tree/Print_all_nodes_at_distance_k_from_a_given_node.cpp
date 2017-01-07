#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;


void print_node(tree_node *root , int k) {
    if(root == NULL || k < 0)
        return;

    if(k == 0)
        cout << root->data << endl;

    print_node(root->left , k-1);
    print_node(root->right , k-1);
}

int print_node_at_k_dis(tree_node *root , tree_node *tmp , int k) {
    if(root == NULL)
        return -1;
    if(root == tmp) {
        print_node(root , k);
        return 0;
    }

    int dl = print_node_at_k_dis(root->left , tmp , k);

    if(dl != -1){
        if(dl + 1 == k)
            cout << root->data << " ";
        else
            print_node(root->right , k-dl-2);

        return 1+dl;
    }

    int dr = print_node_at_k_dis(root->right , tmp , k);

    if(dr != -1) {
        if(dr + 1 == k)
            cout << root->data << " ";
        else
            print_node(root->left , k-dr-2);

        return 1 + dr;
    }

    return -1;

}
/*
int find_node(tree_node *root , tree_node *tmp , int d) {
    if(root == NULL)
        return -1;
    if(root == tmp)
        return d;

    int dis = find_node(root->left , tmp , d+1);
    if(dis != -1)
        return dis;

    dis = find_node(root->right , tmp , d+1);
    return dis;

}

void node_at_k_distance(tree_node *root , tree_node *tmp , int k) {

    int d = 0;
    bool side;

    if(root == tmp) {
       // print_node(root , k);
        return;
    }

    int dis = find_node(root->left , tmp , 1);
    if(dis != -1) {
       // cout << "in left " << dis << endl;
        side = 0;
    }
    else {
        dis = find_node(root->right , tmp , 1);
        side  = 1;
        //cout << "in right " << dis << endl;
    }

    print_node(tmp , k); // take tmp as root and print node at k distance

    if(side == 0) {

    }

}*/
int main()
{
    tree_node *root = NULL;
    int n;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);



    cout << "Tree is (levelorder) " << endl;
    levelorder(root);
    cout << endl;

    int k;
    tree_node *tmp = root->right->left;
   // cout << tmp->data << endl;
    cout << "Enter k " << endl;
    cin >> k;

    int res = print_node_at_k_dis(root , tmp , k);
    if(res == -1)
        cout << "node not present in tree" << endl;


return 0;
}
