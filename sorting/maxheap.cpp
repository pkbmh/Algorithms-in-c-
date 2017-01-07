#include<bits/stdc++.h>

using namespace std;

struct node {
	int val;
	node *left;
	node *right;
	node *parent;
};

struct node * maxheapify(struct node *,struct node *);
void traverse(struct node *);

struct node * create_heap(struct node *root,int data,int count) {
	bitset<64> foo;
	foo = count;
	node *newnode;
	newnode = new node;
	newnode->val = data;
	newnode->parent = NULL;
	newnode->left = NULL;
	newnode->right = NULL;
	if (root == NULL) {
		root = newnode;
		return root;
	} else {
		node *temp;
		temp = new node;
		temp = root;
		int size = floor(log2(count));
		for (int i = size - 1; i >= 1; i--) {
			if (foo.test(i)) {
				temp = temp->right;
			} else {
				temp = temp->left;
			}
		}

		if (foo.test(0)) {
			newnode->parent = temp;
			temp->right = newnode;
		} else {
			newnode->parent = temp;
			temp->left = newnode;
		}
		
		root = maxheapify(root,newnode);
	}
	return root;
}

struct node * maxheapify(struct node *root,struct node *cur) {
	while (cur != root) {
		if (cur->val > cur->parent->val) {
			swap(cur->val,cur->parent->val);
			cur = cur->parent;
		} else {
			break;
		}
	}

	return root;
}

void traverse(struct node *root) {
	queue<struct node *> q;
	q.push(root);

	while (!q.empty()) {
		struct node * temp;
		temp = new node;
		temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if (temp->left != NULL) {
			q.push(temp->left);
		}
		if (temp->right != NULL) {
			q.push(temp->right);
		}
	}
	cout << endl;
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int count = 0;
	struct node * root = NULL;
	for (int i = 0; i < n; i++) {
		count++;
		root = create_heap(root,a[i],count);
	}
	
	traverse(root);

	return 0;
}
