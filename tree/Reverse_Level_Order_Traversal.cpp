#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"
using namespace std;

void reverse_levelorder(tree_node *root) {
    int h = height(root);

    for(int i = h; i >= 1; i--)
        print_at_height(root , i);

    cout << endl;
}
void reverse_levelorder_stack_queue(tree_node *root) {
    queue < tree_node * > qu;
    stack < tree_node * > st;
    qu.push(root);

    while(!(qu.empty())) {
        tree_node *tmp = qu.front();
        qu.pop();

        st.push(tmp);

        // enqueue right first because in stack we push it before left and access it after left;

        if(tmp->right != NULL)
            qu.push(tmp->right);
        if(tmp->left != NULL)
            qu.push(tmp->left);
    }
    while(!(st.empty())) {
        tree_node *tmp = st.top();
        st.pop();
        cout << tmp->data << " ";
    }
    cout << endl;
}
int main()
{
    tree_node *root = NULL;
    int n;
    cout << "Enter number of node we'll generate random tree" << endl;
    cin >> n;
    //srand(time(NULL));

    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "Simple level order traversal of tree" << endl;
    levelorder_recursive(root);
    cout << endl;

    cout << "Reverse level order traversal of tree " << endl;
    reverse_levelorder(root);
    cout << endl;

   // reverse_levelorder_stack_queue(root);
return 0;
}
