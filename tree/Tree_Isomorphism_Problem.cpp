#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

bool check_isomorphism(tree_node *tree1 , tree_node *tree2) {
    if(tree1 == NULL && tree2 == NULL)
        return true;
    if(tree1 == NULL || tree2 == NULL)
        return false;
    if(tree1->data != tree2->data)
        return false;
    bool case1 =  ( check_isomorphism(tree1->right , tree2->right) && check_isomorphism(tree1->left , tree2->left) );
    bool case2 = ( check_isomorphism(tree1->right , tree2->left) && check_isomorphism(tree1->left , tree2->right) );

    return (case1 || case2);
}

pair < tree_node * , tree_node * > create_manually()
{
    tree_node *n1 = create_newnode(1);
    n1->left        = create_newnode(2);
    n1->right       = create_newnode(3);
    n1->left->left  = create_newnode(4);
    n1->left->right = create_newnode(5);
    n1->right->left  = create_newnode(6);
    n1->left->right->left = create_newnode(7);
    n1->left->right->right = create_newnode(8);

    tree_node *n2 = create_newnode(1);
    n2->left         = create_newnode(3);
    n2->right        = create_newnode(2);
    n2->right->left   = create_newnode(4);
    n2->right->right   = create_newnode(5);
    n2->left->right   = create_newnode(6);
    n2->right->right->left = create_newnode(8);
    n2->right->right->right = create_newnode(7);

    return make_pair(n1 , n2);
}
int main()
{
    tree_node *tree1 , *tree2;
    tree1 = tree2 = NULL;

    pair < tree_node * , tree_node * > trees = create_manually();
    tree1 = trees.first;
    tree2 = trees.second;


    cout << "first tree is " << endl;
    levelorder(tree1);
    cout << endl;

    cout << "second tree is " << endl;
    levelorder(tree2);
    cout << endl;

    bool res = check_isomorphism(tree1 , tree2);
    if(res)
        cout << "tree1 and tree2 is isomorphic " << endl;
    else
        cout << "tree1 and tree2 is not isomorphic " << endl;

return 0;
}
