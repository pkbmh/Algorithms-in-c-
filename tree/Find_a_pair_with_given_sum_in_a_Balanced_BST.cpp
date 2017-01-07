#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

tree_node *create_manually() {
    tree_node *root =  create_newnode(15);
    root->left = create_newnode(10);
    root->right = create_newnode(20);
    root->left->left = create_newnode(8);
    root->left->right = create_newnode(12);
    root->right->left = create_newnode(16);
    root->right->right = create_newnode(25);

    return root;
}
bool is_pair(tree_node *root , int sum) {
    stack < tree_node * > st1;
    stack < tree_node * > st2;

    bool done1 , done2;
    done1 = done2 = false;
    int val1 , val2;
    val1 = val2 = 0;

    tree_node *cur1 , *cur2;
    cur1 = cur2 = root;

    while(true) {
        while(done1 == false) {
            if(cur1 != NULL) {
                st1.push(cur1);
                cur1 = cur1->left;
            }
            else {
                if(!st1.empty()){
                    cur1 = st1.top();
                    st1.pop();
                    val1 = cur1->data;
                    cur1 = cur1->right;
                }
                    done1 = true;
            }
        }
        while(done2 == false) {
            if(cur2 != NULL) {
                st2.push(cur2);
                cur2 = cur2->right;
            }
            else {
                if(!st2.empty()) {
                    cur2 = st2.top();
                    st2.pop();
                    val2 = cur2->data;
                    cur2 = cur2->left;
                }
                done2 = true;
            }
        }
        if(val1 != val2 && val1+val2 == sum) {
            cout << val1 << " + " << val2 << " = " << sum << endl;
            return true;
        }
        else if(val1 + val2 < sum)
            done1 = false;
        else if(val1+val2 > sum)
            done2 = false;

        if(val1 >= val2)
            return false;
    }
}
int main()
{
    tree_node *root = create_manually();
    cout << "Tree is (levelorder)" << endl;
    levelorder(root);
    cout << endl;

    cout << "Enter num to find pair" << endl;
    int sum;
    cin >> sum;

    bool res = is_pair(root , sum);
    if(res)
        cout << "yes pair present in tree" << endl;
    else
        cout << "No such pair exist " << endl;

return 0;
}
