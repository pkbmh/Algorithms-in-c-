#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;
static unsigned int seeder = INT_MAX;

tree_node *insert_random(tree_node *root , int t){
    tree_node *tmp = new tree_node;
    tmp->data = t;
    tmp->left = NULL;
    tmp->right = NULL;

    if(root == NULL)
        return tmp;

    int i = t % 2;

    tree_node *ptr = root;


    srand(time(NULL));

    if(i)
        while(ptr->left != NULL && ptr->right != NULL)
            (rand() % 3 == 1) ? ptr = ptr->left : ptr = ptr->right;

    else
        while(ptr->left != NULL && ptr->right != NULL)
            (rand() % 5 == 3) ? ptr = ptr->left : ptr = ptr->right;

    //cout << ptr->data << endl;

    if(ptr->left == NULL)
        ptr->left = tmp;
    else
        ptr->right = tmp;

    return root;
}

bool check_complete(tree_node *root , int index , int total_node) {
   if(root == NULL)
    return true;

   else if(index >= total_node)
    return false;

   return ( check_complete(root->left , (2 * index + 1) , total_node) &&
           check_complete(root->right , (2 * index + 2) , total_node) );
}
int count_node(tree_node *root)
{
    if(root == NULL)
        return 0;
    else return(1 + count_node(root->left) + count_node(root->right));
}
int main()
{
    tree_node *root = NULL;
    int n,t;
    cout << "Enter number of node " << endl;
    cin >> n;

    cout << "Enter value of each node " << endl;

    srand(time(NULL));
    while(n--) {
       //root = insert_node_in_tree(root , t);
        root = insert_random(root , rand()%100);
    }
    cout << "level order traversal is " << endl;
    levelorder(root);


    int total_node = count_node(root);
    cout << "\nTotal node is " << total_node << endl;

    bool res = check_complete(root , 0 ,total_node);
    if(res)
        cout << "Yes tree is complete" << endl;
    else
        cout << "No tree is not complete " << endl;

return 0;
}
