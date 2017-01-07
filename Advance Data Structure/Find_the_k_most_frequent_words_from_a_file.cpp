#include <bits/stdc++.h>
using namespace std;
#define CHARS 26

typedef struct trie_node {
    char c;
    bool isend;
    int freq;
    struct trie_node *child[CHARS];
}trie_node;

typedef struct min_heap{
    int freq;
    //char *word;
    string word;

    struct trie_node *treenode;
    struct min_heap *left;
    struct min_heap *right;
}min_heap;


trie_node *create_newnode(char c) {
    trie_node *tmp = new trie_node;
    tmp->c = c;
    tmp->isend = false;
    tmp->freq = 0;

    for(int i = 0; i < CHARS; i++)
        tmp->child[i] = NULL;

    return tmp;
}

void insert_in_trie(trie_node **root , char *str) {
    if(*root == NULL){
        (*root) = create_newnode(*str);
        str += 1;
        if(*(str) == '\0') {
            (*root)->isend = true;
            (*root)->freq += 1;
            return;
        }
    }

    if((*root)->child[(*str)-97] != NULL) {
        if(*(str+1) != '\0')
            insert_in_trie(&(*root)->child[(*str)-97] , str+1);
        else{
            (*root)->child[(*str)-97]->isend = true;
            (*root)->child[(*str)-97]->freq += 1;
        }
    }
    else {
        insert_in_trie(&(*root)->child[(*str)-97] , str);
    }
}

void traversal_trie(trie_node *root , string word) {
    if(root == NULL)
        return;

    if(root->c != '#')
        word = word + root->c;

    for(int i = 0; i < CHARS; i++)
        if(root->child[i] != NULL)
            traversal_trie(root->child[i], word);

    if(root->isend == true)
        cout << word << "-------------------->" << root->freq << endl;
}
void store_top_k(trie_node *root , string word , priority_queue < pair < int , string > > &pq , int k) {
    if(root == NULL)
        return;

    if(root->c != '#')
        word = word + root->c;

    for(int i = 0; i < CHARS; i++)
        if(root->child[i] != NULL)
            store_top_k(root->child[i], word , pq , k);

    if(root->isend == true) {
            //cout << "hello " << endl;

        //cout << word << "-------------------->" << root->freq << endl;
        if(pq.size() <= k)
        pq.push(make_pair(root->freq , word));
        else {
            pair < int , string > tmp;
            tmp = pq.top();
            if(root->freq > tmp.first) {
                pq.pop();
                pq.push(make_pair(root->freq , word));
            }
        }
    }
}
int main()
{
   FILE *fp = fopen("input_file.txt" , "r");
  // FILE *fp = fopen("input_trie_deletion.txt" , "r");
    char str[1000];

    trie_node *root = create_newnode('#');



    while( fscanf(fp , "%s " , str) != EOF)
        insert_in_trie(&root , str);

    cout << "Created trie is (all word with frequency )" << endl;
    cout << "word     ||    frequency \n" << endl;
     traversal_trie(root , "");

    cout << "Enter k for find top k frequent word " << endl;
    int k;
    cin >> k;

    priority_queue < pair < int  , string > > pq;

    //min_heap *heap = NULL;

    store_top_k(root , "" , pq , k);
    pair < int , string > tmp;

    cout << "k most frequent word is " << endl;
    cout << pq.size() << " size " << endl;
    while(!pq.empty()) {
        tmp = pq.top();
        pq.pop();
        cout << "word   " << tmp.second << "   frequency " << tmp.first << endl;
    }
    cout << endl;
return 0;
}
