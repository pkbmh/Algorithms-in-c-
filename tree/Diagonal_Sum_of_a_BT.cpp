#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;


void print_diagonal_sum(tree_node *root) {
    if(root == NULL)
        return;
    int diagonal[100];
    memset(diagonal , 0 , sizeof(diagonal));

    pair < tree_node * , int > tmp;
    //tmp = make_pair(NULL , 0);
    queue < pair < tree_node * , int > > qu;
    qu.push(make_pair(root , 0));

    while(!qu.empty()) {
      tmp = qu.front();
      qu.pop();
      int d = tmp.second;
      diagonal[d] += (tmp.first)->data;

      if(tmp.first->left != NULL)
        qu.push(make_pair((tmp.first)->left , d+1));
      if(tmp.first->right != NULL)
        qu.push(make_pair((tmp.first)->right , d));
    }

    for(int i = 0; ; i++) {
        if(diagonal[i] == 0)
            break;
        cout << "diagonal " << i << " sum = " <<diagonal[i] << endl;
    }
}
tree_node *create_manually()
{
    tree_node *root = create_newnode(1);
        root->left = create_newnode(2);
        root->right = create_newnode(3);
        root->left->left = create_newnode(9);
        root->left->right = create_newnode(6);
        root->right->left = create_newnode(4);
        root->right->right = create_newnode(5);
        root->right->left->left = create_newnode(12);
        root->right->left->right = create_newnode(7);
        root->left->right->left = create_newnode(11);
        root->left->left->right = create_newnode(10);
    return root;
}
int main()
{
    int n;
    tree_node *root = NULL;
    root = create_manually();
    /*
    cout << "Enter number of node in tree" << endl;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%10);
    */
    cout << "Created tree  is (levelorder)" << endl;
    levelorder(root);


    print_diagonal_sum(root);

return 0;
}
