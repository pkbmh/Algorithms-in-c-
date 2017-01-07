#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

void print_list(tree_node *root) {
    while(root != NULL) {
        cout << root->data << "->";
        root = root->right;
    }
    cout << "->NULL" << endl;
}
void convert_into_list(tree_node **start , tree_node **end , tree_node *root) {
    if(root == NULL)
        return;

    if(root->left != NULL)
        convert_into_list(start , end , root->left);

    root->left = (*end);

    if(*end != NULL)
        (*end)->right = root;
    else
        (*start) = root;

    (*end) = root;

    if(root->right != NULL)
        convert_into_list(start , end , root->right);

}


bool find_triplet_using_list(tree_node *start , tree_node *end)
{
    tree_node *tmp1 , *tmp2;

    while(start->right != end && (start->data < 0) ) {
        int sum = start->data * (-1);
        tmp1 = start->right;
        tmp2 = end;

        while(tmp1 != end) {
                int t = tmp1->data+tmp2->data;
            if(sum == t) {
                cout << "triplet is " << endl;
                cout << "{" << start->data << "," << tmp1->data << "," << tmp2->data << "}" << endl;
                return true;
            }

            if(sum < t)
                tmp2 = tmp2->left;
            else
                tmp1 = tmp1->right;
        }

        start = start->right;
    }

    return false;
}
bool find_triplet_in_tree(tree_node *root) {
    tree_node *start , *end;
    start = end = NULL;
    convert_into_list(&start , &end , root);

 /*    cout << "converted list is " << endl;
    print_list(end);
*/

    bool res = find_triplet_using_list(start , end);

   return res;
}

int main()
{
    tree_node *root = NULL;
    int n,t;
    cout << "Enter number of node " << endl;
    cin >> n;
    cout << "Enter value of each node " << endl;

    while(n--) {
        cin >> t;
        root = insert_node_in_tree(root , t);
    }

    cout << "inorder traverse " << endl;
    inorder(root);
    cout << endl << endl;

    bool res = find_triplet_in_tree(root);

    if(!res)
        cout << "NO triplet not present" << endl;

return 0;
}
