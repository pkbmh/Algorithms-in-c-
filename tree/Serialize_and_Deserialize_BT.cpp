#include <bits/stdc++.h>
#include "BINARY_TREE.cpp"

using namespace std;

void serialize(tree_node *root , FILE *fp) {
    if(root == NULL) {
        fprintf(fp , "%d " , -1);
        return;
    }
    fprintf(fp , "%d " , root->data);
    serialize(root->left , fp);
    serialize(root->right , fp);

}

void deserialize(tree_node **root, FILE *fp) {
    int val;
    if(!fscanf(fp , "%d " , &val) || val == -1)
        return;

    *root = create_newnode(val);

    deserialize(&(*root)->left , fp);
    deserialize(&(*root)->right , fp);
}
tree_node *create_manually() {
    tree_node *tmp = create_newnode(20);
    tmp->left = create_newnode(8);
    tmp->left->right = create_newnode(12);
    tmp->left->left = create_newnode(4);
    tmp->left->right->left = create_newnode(10);
    tmp->left->right->right = create_newnode(14);

    return tmp;
}
int main()
{
    tree_node *root = NULL;
    int n;

    root = create_manually();

    cout << "Initial tree  is levelorder" << endl;
    levelorder(root);

    FILE *fp = fopen("tree_backup.txt" , "w");

    serialize(root , fp);

    fclose(fp);

    fp = fopen("tree_backup.txt" , "r");

    delete root;
    root = NULL;

    deserialize(&root , fp);

    cout << "After deserialize tree  is levelorder " << endl;
    levelorder(root);

return 0;
}
