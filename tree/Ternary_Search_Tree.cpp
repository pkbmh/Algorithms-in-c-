#include <bits/stdc++.h>
using namespace std;

typedef struct ternary_node {
    char data;
    bool isend;
    struct ternary_node *left;
    struct ternary_node *equal;
    struct ternary_node *right;
}ternary_node;

ternary_node *create_newnode(char c) {
    ternary_node *tmp = new ternary_node;
    tmp->data = c;
    tmp->isend = false;
    tmp->left = tmp->equal = tmp->right = NULL;

    return tmp;
}
void insert_node_in_ternary(ternary_node **root , char *str) {
    if((*root) == NULL)
        (*root) = create_newnode(*str);

    if( (*str) < (*root)->data )
        insert_node_in_ternary(&(*root)->left  , str);
    else if( (*str) > (*root)->data )
        insert_node_in_ternary(&(*root)->right , str);
    else {
        if(*(str+1))
            insert_node_in_ternary( &(*root)->equal , str+1);
        else
            (*root)->isend = true;
    }

}

void traversal(ternary_node *root , string str) {
    if(root == NULL)
        return;
    if(root->isend == true) {
        string t = str + root->data;
        cout << t << endl;
    }

    traversal(root->left , str);
    traversal(root->equal , str+root->data);
    traversal(root->right , str);

}
bool search_in_tree(ternary_node *root , char *word) {
    if(root == NULL || (*word) == '\0')
        return false;

    if((*word) < root->data)
        return search_in_tree(root->left , word);
    else if((*word) > root->data)
        return search_in_tree(root->right , word);
    else {
        if(*(word+1) != '\0')
            return search_in_tree(root->equal , word+1);

        if(root->isend == true)
        return true;
        else
            return false;
    }
}

int  search_or_correct(ternary_node *root , char *word , string correct) {
        if(root == NULL)
        return -1;

    if((*word) < root->data)
        return search_or_correct(root->left , word , correct);
    else if((*word) > root->data)
        return search_or_correct(root->right , word , correct);
    else {
        if(*(word+1) != '\0')
            return search_or_correct(root->equal , word+1 , correct+root->data);

        if(root->isend)
            return 1;
        else {
            cout << "This word is not in tree correction is below" << endl;
            traversal(root , correct);
        }
    }
}

int main()
{
    ternary_node *root = NULL;
    int n;
    char str[1000];

    cout << "Enter number of word " << endl;
    cin >> n;

    cout << "Enter each word" << endl;
    while(n--) {
        cin >> str;
        insert_node_in_ternary(&root , str);
    }
    cout << "traversal of tree is (print all word) " << endl;
    traversal(root , "");

    cout << "enter word to search" << endl;
    char word[1000];
    cin >> word;

    bool res = search_in_tree(root , word);
    if(res)
        cout << "word found in tree " << endl;
    else
        cout << "word not found in tree" << endl;

    cout << "Enter word to search or correct" << endl;
    cin >> word;

    int cres;
    cres = search_or_correct(root , word , "");
    if(cres == -1)
        cout << "this word not in tree and no correction " << endl;
    else if(cres == 1)
        cout << "word found in tree" << endl;

return 0;
}
