#include <bits/stdc++.h>
using namespace std;
#define ALPHABET 26

typedef struct trie_node {
    char data;
    bool isend;
    struct trie_node *child[ALPHABET];
}trie_node;

trie_node *create_newnode(char c) {
    trie_node *tmp = new trie_node;
    tmp->data = c;
    tmp->isend = false;
    for(int i = 0; i < ALPHABET; i++)
        tmp->child[i] = NULL;

    return tmp;
}

void insert_node_in_trie(trie_node **root , char *str) {
    if( (*root) == NULL)
        (*root) = create_newnode((*str));

    if((*root)->data == (*str)) {
        if(*(str+1) != '\0')
            insert_node_in_trie(&(*root)->child[*(str+1)-97] , str+1);
        else
            (*root)->isend = true;
    }
    else
        insert_node_in_trie(&(*root)->child[*(str)-97] , str);
}

void traversal_trie(trie_node *root , string str) {
    if(root == NULL)
        return;

    if(root->data != ' ')
    str = str + root->data;
    for(int i = 0; i < ALPHABET; i++)
        if(root->child[i] != NULL)
            traversal_trie(root->child[i] , str);

     if(root->isend)
        cout << str << endl;
}
int search_and_correct(trie_node *root , char *str , string correct) {
    if(root == NULL)
        return -1;

    if(root->child[(*str)-97] != NULL) {
        if(*(str+1) != '\0')
            return search_and_correct(root->child[(*str)-97] , str+1 , correct+(*str));
        else if(root->child[(*str)-97]->isend == true)
            return 1;
        else {
            cout << "this word not in tree correction is " << endl;
            traversal_trie(root->child[(*str)-97] , correct);
        }
    }
    else
        return -1;

}
int main()
{
    trie_node *root = NULL;
    char dum = ' ';
    root = create_newnode(dum);
    int n;
    char str[1000];
    cout << "Enter number of word" << endl;
    cin >> n;

    cout << "Insert all word" << endl;
    while(n--) {
        cin >> str;
        insert_node_in_trie(&root , str);
    }

    cout << "All word in tree is " << endl;
    traversal_trie(root , "");

    cout << "Enter a word to search" << endl;
    cin >> str;

    int res = search_and_correct(root , str , "");
    //cout << "res " << res << endl;
    if(res == -1)
        cout << "word not in tree no correction" << endl;
    else if(res == 1)
        cout << "word found in tree " << endl;


return 0;
}
