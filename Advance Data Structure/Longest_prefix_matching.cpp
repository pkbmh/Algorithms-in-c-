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

void longest_prefix(trie_node *root , char *str , string &tmp , string pre) {
    if(root == NULL)
        return;
    if(root->child[(*str)-97] != NULL) {
        if(*(str+1) != '\0') {
            if(root->child[(*str)-97]->isend == true)
                tmp = pre+(*str);

            longest_prefix(root->child[(*str)-97] , str+1 , tmp , pre+(*str));
        }
        else if(*(str+1) == '\0' && root->child[(*str)-97]->isend == true)
            tmp = pre+(*str);
    }
}
int main()
{
    trie_node *root = NULL;
    char dum = ' ';
    root = create_newnode(dum);
    int n;
    char str[1000];
   /* cout << "Enter number of word" << endl;
    cin >> n;

    cout << "Insert all word" << endl;
    */
    FILE *fp = fopen("input_Longest_prefix.c" , "r");
    fscanf(fp , "%d\n", &n);

    while(n--) {
        //cin >> str;
        fscanf(fp , "%s\n" , str);
        insert_node_in_trie(&root , str);
    }

    cout << "All word in tree is " << endl;
    traversal_trie(root , "");

    //cout << "Enter word to find prefix " << endl;
    //cin >> str;
    fscanf(fp , "%s\n" , str);
    fclose(fp);

    string tmp;
    longest_prefix(root , str , tmp , "");
    cout << "Longest prefix is = " << tmp << endl;

return 0;
}

