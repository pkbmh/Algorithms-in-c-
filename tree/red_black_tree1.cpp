#include <bits/stdc++.h>
using namespace std;

#define red 1
#define black 0

typedef struct node {
	int data;
	int color;
	struct node *parent;
	struct node *child[2];
}node;
node *root;
node *nil;
int height(node *root) {
	if(root == nil)
	return 0;
	int lh = height(root->child[0]);
	int rh = height(root->child[1]);
	
	return ((lh > rh) ? lh+1 : rh+1);
}
void travel(node *tmp) {
	
	if(tmp == nil)
	return;
	
	travel(tmp->child[0]);
	
	if(tmp->parent != nil)
	printf("node = %d parent = %d\n" , tmp->data , tmp->parent->data);
	
	else
	 printf("node = %d parent = null\n", tmp->data);
	
	travel(tmp->child[1]);
}
node *left_rotate(node *root , node *x) {
	node *y;
	y = x->child[1];
	x->child[1] = y->child[0];
	
	if(y->child[0] != nil) 
	y->child[0]->parent = x;
	
	y->parent = x->parent;

	if(x->parent == nil)
		root = y;
	else if(x == x->parent->child[0])
		x->parent->child[0] = y;
	else 
		x->parent->child[1] = y;
			
	y->child[0] = x;
	x->parent = y;
return root;
}
node *right_rotate(node *root , node *x) {
	node *y;
	y = x->child[0];
	x->child[0] = y->child[1];
	
	if(y->child[1] != nil)
	y->child[1]->parent = x;
	
	y->parent = x->parent;
	
	if(x->parent == nil)
		root = y;
	else if(x == x->parent->child[0])
		x->parent->child[0] = y;
	else
		x->parent->child[1] = y;
	
	y->child[1] = x;
	x->parent = y;

return root;	 

} 
		 
node *insert_fixup(node *z) {
	node *zp,*zpp,*zu;
	while(z->parent->color == red) {
		zp = z->parent;
		zpp = zp->parent;
		
		if(zp == zpp->child[0]) {
			zu = zpp->child[1];
				if(zu->color == red) {
					zp->color = black;
					zu->color = black;
					zpp->color = red;
					z = zpp;
				}
				else {
					if(z == zp->child[1]) {
						root = left_rotate(root , zp);
						z = zp;
						zp = z->parent;
					}
				zp->color = black;
				zpp->color = red;
				root = right_rotate(root , zpp);
				}
		}
		else {
			if(zp == zpp->child[1]) {
			zu = zpp->child[0];
				if(zu->color == red) {
					zp->color = black;
					zu->color = black;
					zpp->color = red;
					z = zpp;
				}
				else {
					if(z == zp->child[0]) {
 
						root = right_rotate(root , zp);
						z = zp;
						zp = z->parent;
					}
					zp->color = black;
					zpp->color = red;
					root = left_rotate(root , zpp); 
				}
			}
		}
	}
root->color = black;
return root;
}
node *insert(node *root , int x) {
	node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));

	tmp->data = x;
	tmp->color = red;
	tmp->child[0] = tmp->child[1] = tmp->parent = nil;
	
	if(root == nil){ 
		root = tmp;
		root->color = black;
		root->parent= nil;
	return root;
	}
	node *p , *pt;
	p = pt = root;
	
	while(p != nil) {
		 pt = p;
		p = p->child[p->data < x];
	}

	tmp->parent = pt;

	pt->child[pt->data < x] = tmp;
	root = insert_fixup(tmp);

return root;
} 
 	
int main()
{
	int n,t;
	scanf("%d", &n);
	nil = (struct node *)malloc(sizeof(struct node));
	nil->color = black;
	nil->data = -1;
	
	root = nil;
	for(int i = 0; i < n; i++) {
		scanf("%d", &t);
		root = insert(root , t);
	}
	printf("\theight of tree = %d\n", height(root));
	travel(root);
return 0;
}
