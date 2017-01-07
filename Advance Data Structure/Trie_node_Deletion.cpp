#include <bits/stdc++.h>
using namespace std;
#define CHARS 26

typedef struct trie_node {
    char c;
    bool isend;

    struct trie_node *child[CHARS];
}trie_node;

trie_node *create_newnode(char c) {
    trie_node *tmp = new trie_node;
    tmp->c = c;
    tmp->isend = false;

    for(int i = 0; i < CHARS; i++)
        tmp->child[i] = NULL;

    return tmp;
}
void insert_in_trie(trie_node **root , char *str) {
    if(*root == NULL)
        (*root) = create_newnode(*str);

    if((*root)->c == (*str)) {
        if(*(str+1) != '\0')
            insert_in_trie(&(*root)->child[*(str+1)-97] , str+1);
        else
            (*root)->isend = true;
    }
    else
        insert_in_trie(&(*root)->child[(*str)-97] , str);
}
void traversal_trie(trie_node *root , string str) {
    if(root == NULL)
        return;
    if(root->c != '#')
        str += root->c;

    for(int i = 0; i < CHARS; i++)
        if(root->child[i] != NULL)
            traversal_trie(root->child[i] , str);

    if(root->isend)
        cout << str << endl;
}
bool is_leaf(trie_node *root) {
    for(int i = 0; i < CHARS; i++)
        if(root->child[i] != NULL)
            return false;

    return true;
}
bool delete_in_trie(trie_node **root , char *str) {
    if(*root == NULL)
        return false;
    if((*root)->c == (*str)) {

        if(*(str+1) != '\0')
            return delete_in_trie(&(*root)->child[*(str+1)-97] , str+1);
        else {
            bool leaf = is_leaf(*root);
            if(leaf)
                (*root) = NULL;
            else
                (*root)->isend = false;

            return true;
        }
    }
    else
        return delete_in_trie(&(*root)->child[(*str)-97] , str);
}
int main()
{
    trie_node *root = create_newnode('#');
    FILE *fp = fopen("input_trie_deletion.txt" , "r");
    char str[1000];

    while( fscanf(fp , "%s" , str) != EOF)
        insert_in_trie(&root , str);

    cout << "Create tree is (all word in trie) " << endl;
    traversal_trie(root , "");
    cout <<endl;
    //while(true) {
    cout << "Enter key for deletion " << endl;
    cin >> str;

    bool res = delete_in_trie(&root , str);
    if(res == false)
        cout << "key not in tree " << endl;
    else{
        cout << "After deletion tree is " << endl;
        traversal_trie(root , "");
        cout << endl;
    }
return 0;
}
