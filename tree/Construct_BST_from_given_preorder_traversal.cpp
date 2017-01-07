#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

tree_node *new_node(int t) {
    tree_node *tmp = new tree_node;
    tmp->data = t;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

tree_node *construct_tree(int pre[] , int size) {
    stack < tree_node * > st;

    tree_node *root = new_node(pre[0]);

    st.push(root);

    //cout << "size " << size << endl;
    for(int i = 1; i < size; i++) {
        tree_node *ptr = NULL;

        while(!(st.empty()) && pre[i] > (st.top()->data) ) {
              ptr = st.top();
               st.pop();
        }

        if(ptr != NULL) {
            ptr->right = new_node(pre[i]);
            st.push(ptr->right);
        }
        else{
            (st.top())->left = new_node(pre[i]);
            st.push((st.top())->left);
        }
    }
    return root;
}

int main()
{
    tree_node *root = NULL;

    int n,t;
    cout << "Enter number of node in tree " << endl;
    cin >> n;

    int pre[n];
    cout << "Enter preorder traversal " << endl;
    for(int i = 0; i < n; i++)
        cin >> pre[i];


    root = construct_tree(pre , n);
    cout << "inoreder traversal is " << endl;
    inorder(root);

return 0;
}
