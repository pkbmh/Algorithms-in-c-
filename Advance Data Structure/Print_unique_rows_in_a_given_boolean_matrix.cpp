#include <bits/stdc++.h>
using namespace std;

typedef struct trie_node {
    char c;
    bool isend;
    int freq;
    struct trie_node *one;
    struct trie_node *zero;
}trie_node;

trie_node *create_newnode(char c) {
    trie_node *tmp = new trie_node;
    tmp->c = c;
    tmp->freq = 0;
    tmp->isend = false;
    tmp->one = NULL;
    tmp->zero = NULL;

    return tmp;
}

void insert_in_trie(trie_node **root , char *str) {
    if(*root == NULL)
        (*root) = create_newnode(*str);

    if((*root)->c == (*str)) {
            if(*(str+1) == '\0') {
                (*root)->isend = true;
                (*root)->freq += 1;
            }
            else {
                if(*(str+1) == '0')
                    insert_in_trie(&(*root)->zero , str+1);
                else
                    insert_in_trie(&(*root)->one , str+1);
            }
    }
    else {
        if(*(str) == '0')
            insert_in_trie(&(*root)->zero , str);
        else
            insert_in_trie(&(*root)->one , str);
    }
}

void traversal_trie(trie_node *root , string str) {
    if(root == NULL)
        return;
    if(root->c != '#')
        str = str + root->c;

    traversal_trie(root->zero , str);
    traversal_trie(root->one , str);

    if(root->isend) {
        int len = str.length();
        for(int i = 0; i < len; i++)
            cout << str[i] << " ";

        cout << "   ->> freq is :: " << root->freq << endl;
    }

}
int main()
{
    trie_node *root = create_newnode('#');

    int row , col;
    cout << "Enter number of row and column of given matrix" << endl;
    cin >> row >> col;
    int matrix[row][col];

    int i,j;
    char str[1000];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> matrix[i][j];
            str[j] = (matrix[i][j]+48);
        }

       str[col] = '\0';
      // cout << str << endl;
        insert_in_trie(&root , str);

    }
    cout << "Unique row and freq of row " << endl;
    traversal_trie(root , "");

return 0;
}
