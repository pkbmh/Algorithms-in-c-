#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

int search_in(int in[] , int si , int ei , int data) {
    int i;
    for(i = si; i <= ei; i++)
        if(in[i] == data)
            return i;

    return -1;
}

int *extract_element(int in[] , int level[] , int m ,int n) {
    int *nlevel = new int[m];
    int j = 0;

    for(int i = 0; i < n; i++) {
        if(search_in(in , 0 , m-1 ,level[i]) != -1)
            nlevel[j] = level[i] , j++;
    }
    return nlevel;
}
tree_node *construct_tree(int in[] , int level[] , int si , int ei , int n) {
    if(si > ei)
        return NULL;

    tree_node *root = create_newnode(level[0]);


    if(si == ei)
        return root;

    int indx_next = search_in(in , si , ei , root->data);

    int *llevel = extract_element(in , level ,indx_next , n);
    int *rlevel = extract_element(in+indx_next+1 , level ,n-indx_next-1 , n);

    root->left = construct_tree(in , llevel ,si , indx_next-1 , n);
    root->right = construct_tree(in , rlevel , indx_next+1 , ei , n);

    delete [] llevel;
    delete [] rlevel;

    return root;
}
int main()
{
    int n;
    cout << "Enter number of node in tree" << endl;
    cin >> n;

    int in[n] , level[n];
    cout << "Enter inorder traversal " << endl;
    for(int i = 0; i < n; i++)
        cin >> in[i];
    cout << "Enter levelorder traversal " << endl;
    for(int i = 0; i < n; i++)
        cin >> level[i];

    tree_node *root = construct_tree(in , level , 0, n-1 , n);
    cout << "constructed tree is (levelorder) " << endl;
    levelorder(root);
    cout << endl;

return 0;
}
