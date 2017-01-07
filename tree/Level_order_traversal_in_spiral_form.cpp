#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

void print_spiral(tree_node *root , int level , bool lts) {
    if(root == NULL)
        return;
    if(level == 1)
        cout << root->data << " ";
    else if(level > 1){
        if(lts) {
            print_spiral(root->left , level-1 , lts);
            print_spiral(root->right , level-1 , lts);
        }
        else {
            print_spiral(root->right , level-1 , lts);
            print_spiral(root->left , level-1 , lts);
        }
    }
}
void levelorder_spiral(tree_node *root) {
    int h = height(root);
    bool lts = false;

    for(int i = 1; i <= h; i++) {
        print_spiral(root , i , lts);
        lts = !lts;
    }
}

void levelorder_spiral_using_stack(tree_node *root) {
    stack < tree_node * > st1;
    stack < tree_node * > st2;

    st1.push(root);
    tree_node *tmp;

    while(!st1.empty() || !st2.empty()) {

            while(!st1.empty()) {
                tmp = st1.top();
                st1.pop();
                cout << tmp->data << " ";
                if(tmp->right != NULL)
                    st2.push(tmp->right);
                if(tmp->left != NULL)
                    st2.push(tmp->left);
            }

            while(!st2.empty()) {
                tmp = st2.top();
                st2.pop();
                cout << tmp->data << " ";
                if(tmp->left != NULL)
                    st1.push(tmp->left);
                if(tmp->right != NULL)
                    st1.push(tmp->right);
            }
    }

}
int main()
{
    tree_node *root = NULL;
    cout << "Enter number of node " << endl;
    int n;
    cin >> n;

    while(n--)
        root = insert_node_in_tree(root , rand()%100);

    cout << "Simple level order traversal" << endl;
    levelorder(root);
    cout << endl;

    cout << "Level order traversal in spiral form" << endl;
    levelorder_spiral(root);
    cout << endl;
    //levelorder_spiral_using_stack(root);
    cout << endl;

return 0;
}
