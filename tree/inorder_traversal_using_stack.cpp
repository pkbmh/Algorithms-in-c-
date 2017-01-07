#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

void inorder_using_stack(tree_node *root) {
    if(root == NULL)
        return;
    stack < tree_node * > st;
    tree_node *current = root;


    while(current != NULL || !st.empty()) {

        while(current != NULL) {
            st.push(current);
            current = current->left;
        }
        tree_node *tmp = st.top();
        st.pop();
        cout << tmp->data << " ";
        current = tmp->right;

    }
    cout << endl;
}
int main()
{
    tree_node *root = NULL;
    int n;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%10);

    cout << "Inorder traversal " << endl;
    inorder_using_stack(root);
    cout << endl;
return 0;
}
