#include <bits/stdc++.h>
using namespace std;
#define CHARS 26

typedef struct trie_node {
    char c;
    bool isend;
    int freq;
    struct trie_node *child[CHARS];
}trie_node;

typedef struct min_heap_node{
    int freq;
    string word;
    struct trie_node *treenode;
}min_heap_node;

typedef struct min_heap {
    int capacity;
    int filled;
    min_heap_node *min_heap_array;
}min_heap;

min_heap *create_min_heap(int capacity) {
    min_heap *my_min_heap = new min_heap;
    my_min_heap->capacity = capacity;
    my_min_heap->filled = 0;
    my_min_heap->min_heap_array = new min_heap_node[capacity];

    return my_min_heap;
}

min_heap_node create_min_heap_node(trie_node *root , string word) {
    min_heap_node tmp;
    tmp.freq = root->freq;
    tmp.word = " " + word;
    tmp.treenode = root;

    return tmp;
}

void rebuild_min_heap(min_heap *my_min_heap , int i) {
    int next = 2 * i;
    int ch = i;
    int size  = my_min_heap->filled;

    if(next+1 < size && my_min_heap->min_heap_array[ch].freq > my_min_heap->min_heap_array[next+1].freq)
        ch = next+1;
    if(next+2 < size && my_min_heap->min_heap_array[ch].freq > my_min_heap->min_heap_array[next+2].freq)
        ch = next+2;

    if(ch != i) {
        min_heap_node tmp = my_min_heap->min_heap_array[ch];
        my_min_heap->min_heap_array[ch] = my_min_heap->min_heap_array[i];
        my_min_heap->min_heap_array[i] = tmp;
    }
}
void min_heapify(min_heap *my_min_heap) {
    int n,i;
    n = my_min_heap->filled;

    for(i = (n-1)/2; i >= 0; i--)
        rebuild_min_heap(my_min_heap , i);
}
void insert_in_min_heap(trie_node *root , string word , min_heap *my_min_heap)  {
    if(my_min_heap->filled < my_min_heap->capacity) {
        my_min_heap->min_heap_array[my_min_heap->filled] = create_min_heap_node(root , word);
        my_min_heap->filled += 1;
        min_heapify(my_min_heap);
    }
    else if(my_min_heap->min_heap_array[0].freq < root->freq){
        my_min_heap->min_heap_array[0] = create_min_heap_node(root , word);
       min_heapify(my_min_heap);
    }
}

min_heap_node extract_from_min_heap(min_heap *my_min_heap) {
    min_heap_node tmp = my_min_heap->min_heap_array[0];
    int i = my_min_heap->filled-1;
    my_min_heap->min_heap_array[0] = my_min_heap->min_heap_array[i];
    my_min_heap->filled -= 1;
    min_heapify(my_min_heap);

    return tmp;
}
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

    if(root->c != '0')
        word = word + root->c;

    for(int i = 0; i < CHARS; i++)
        if(root->child[i] != NULL)
            traversal_trie(root->child[i], word);

    if(root->isend == true)
        cout << word << "-------------------->" << root->freq << endl;
}
void store_top_k(trie_node *root , string word , min_heap *my_min_heap , int k) {
    if(root == NULL)
        return;

    if(root->c != '0')
        word = word + root->c;

    for(int i = 0; i < CHARS; i++)
        if(root->child[i] != NULL)
            store_top_k(root->child[i], word , my_min_heap , k);

    if(root->isend == true) {
        insert_in_min_heap(root , word , my_min_heap);
    }
}

int main()
{
    FILE *fp = fopen("input_file.txt" , "r");
    char str[1000];
    char dup[1000];

    trie_node *root = create_newnode('0');


    while( fscanf(fp , "%s " , str) != EOF)
        insert_in_trie(&root , str);

    cout << "Created trie is (all word with frequency )" << endl;
    cout << "word     ||    frequency \n" << endl;
     traversal_trie(root , "");

    cout << "Enter k for find top k frequent word " << endl;
    int k;
    cin >> k;
    min_heap *my_min_heap;
    my_min_heap = create_min_heap(k);

    store_top_k(root , "" , my_min_heap , k);

    cout << "most frequent word are below with there frequency " << endl;
    for(int i = 0; i < my_min_heap->capacity; i++) {
    min_heap_node tmp = extract_from_min_heap(my_min_heap);
        cout << tmp.word << " : " << tmp.freq << endl;
        //cout << my_min_heap->min_heap_array[i].word << " : " << my_min_heap->min_heap_array[i].freq << endl;
    }
return 0;
}
