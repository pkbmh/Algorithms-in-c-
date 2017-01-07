#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

void merge_arr(vector < int > v1 , vector < int > v2 , vector < int > &v) {
    int i,j,size1,size2;
    size1 = v1.size();
    size2 = v2.size();
    i = j = 0;

    while(i < size1 && j < size2) {
        if(v1[i] < v2[j]) {
            v.push_back(v1[i]);
            i++;
        }
        else {
            v.push_back(v2[j]);
            j++;
        }
    }

    while(i < size1) {
        v.push_back(v1[i]);
        i++;
    }
    while(j < size2) {
        v.push_back(v2[j]);
        j++;
    }
}
void create_balance_tree(tree_node **root , vector < int > &v , int l , int h) {
    if(l >= h)
        return ;
    int mid = (l+h) / 2;

    if(*root == NULL)
        *root = create_newnode(v[mid]);

    //cout << root->data << endl;
  //  return root;
   create_balance_tree(&(*root)->left , v , l , mid);
   create_balance_tree(&(*root)->right , v , mid+1 , h);
}
void inorder_store(tree_node *root , vector < int > &v) {
    if(root == NULL)
        return;
    inorder_store(root->left , v);
    v.push_back(root->data);
    inorder_store(root->right , v);
}
tree_node *merge_tree(tree_node *tree1 , tree_node *tree2) {
    vector < int > v1;
    vector < int > v2;

    inorder_store(tree1 , v1);
    inorder_store(tree2 , v2);

    vector < int > v;
    merge_arr(v1 , v2 , v);

    int size = v.size();

    tree_node *root = NULL;

    create_balance_tree(&root , v , 0 , size);
    return root;
}
int main()
{
    tree_node *tree1  = create_newnode(100);
    tree1->left         = create_newnode(50);
    tree1->right        = create_newnode(300);
    tree1->left->left   = create_newnode(20);
    tree1->left->right  = create_newnode(70);

    tree_node *tree2  = create_newnode(80);
    tree2->left         = create_newnode(40);
    tree2->right        = create_newnode(120);

    cout << "first tree is (levelorder)" << endl;
    levelorder(tree1);
    cout << endl;

    cout << "second tree is (levelorder)" << endl;
    levelorder(tree2);
    cout << endl;

    tree_node *root = merge_tree(tree1  ,tree2);
    cout << "merged tree is (levelorder)" << endl;
    inorder(root);
    cout << endl;

return 0;
}
