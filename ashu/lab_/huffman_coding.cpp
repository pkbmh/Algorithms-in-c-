#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    char ch;
    int freq;
    struct node *left;
    struct node *right;
} node;

struct node_comparison {
    bool operator () ( const node* a, const node* b ) const {
        return a->freq > b->freq;
    }
};

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d", arr[i]);
    printf("\n");
}

void print_codes(node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%c : ", root->ch);
        print_array(arr, top);
    }
}

int main() {
    char str[10000];
    scanf("%s", str);
    int n = strlen (str), i, fr;
    node *root = NULL;
    priority_queue <node *, vector <node *> , node_comparison> myqueue;
    for (i = 0; i < n; i++) {
        scanf ("%d", &fr);
        root = new node;
        root->ch = str[i];
        root->freq = fr;
        root->left = NULL;
        root->right = NULL;
        myqueue.push(root);
    }

    node *lchild, *rchild, *top;

    while (myqueue.size() != 1) {

        lchild = myqueue.top();
        myqueue.pop();
        rchild = myqueue.top();
        myqueue.pop();
        top = new node;
        top->ch = '@';
        top->freq = lchild->freq + rchild->freq;
        top->left = lchild;
        top->right = rchild;
        myqueue.push(top);
    }

    root = myqueue.top();
    myqueue.pop();
    int arr[1000];
    print_codes(root, arr, 0);
    return 0;
}
