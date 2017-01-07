#include <bits/stdc++.h>
using namespace std;

#define CHARS 11

typedef struct trie_node {
    char *url;
    bool isend;
    struct trie_node *child[CHARS];
}trie_node;

trie_node *create_newnode() {
    trie_node *tmp = new trie_node;
    tmp->url = NULL;
    tmp->isend = false;

    for(int i = 0; i < CHARS; i++)
        tmp->child[i] = NULL;

    return tmp;
}

int get_index(char c) {
    return (c == '.') ? 10 : (c-'0');
}
char get_index_char(int i) {
    return (i == 10) ? '.' : char(i+48);
}
void insert_node_in_trie(trie_node **root , char *ip , char *url) {

    if((*root) == NULL) {
        (*root) = create_newnode();
        ip = ip + 1;
    }

    int index = get_index((*ip));
    if(*ip == '\0'){
            (*root)->isend = true;
            (*root)->url = new char[strlen(url) + 1];
            strcpy((*root)->url, url);
            return;
    }

    if( (*root)->child[index] != NULL ) {
        if(*(ip+1) != '\0')
            insert_node_in_trie(&(*root)->child[index] , ip+1 , url);
        else {
            (*root)->isend = true;
            (*root)->url = new char[strlen(url) + 1];
            strcpy((*root)->url, url);
        }
    }
    else
        insert_node_in_trie(&(*root)->child[index] , ip , url);
}

void traversal_trie(trie_node *root , string str) {
    if(root == NULL)
        return;
    if(root->isend)
        cout << root->url << "   |  " << str << endl;

    for(int i = 0; i < CHARS; i++) {
        if(root->child[i] != NULL) {
            traversal_trie(root->child[i] , str+get_index_char(i));
        }
    }
}
void search_in_trie(trie_node *root , char *ip) {
    int index = get_index((*ip));
    if(root == NULL) {
        cout << "This ip address not found" << endl;
        return;
    }
    if(root->child[index] != NULL) {
        if(*(ip+1) != '\0')
            search_in_trie(root->child[index] , ip+1);
        else if(root->child[index]->isend)
            cout << root->child[index]->url << endl;
        else
            cout << "this ip address not found" << endl;
    }
    else
        cout << "this ip address not found " << endl;
}
int main()
{
    trie_node *root = create_newnode();
    char ip[1000];
    char url[1000];
    int n;
    FILE *fp = fopen("input_DNS_Look_Up.txt" , "r");

    fscanf(fp , "%d\n", &n);

    while(n--) {
        fscanf(fp , "%s%s\n" , ip , url);
        insert_node_in_trie(&root , ip , url);
    }
   fclose(fp);

    cout << "traversal of tree print all domain name and ip " << endl;
    cout << " domain name       |    ip address \n" << endl;
    traversal_trie(root , "");

    cout << "Enter ip address to search domain" << endl;
    cin >> ip;
    search_in_trie(root , ip);

return 0;
}
