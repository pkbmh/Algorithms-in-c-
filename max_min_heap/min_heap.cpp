#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

#define PB push_back
#define FOR(i , n) for(i = 0; i < n; i++)
#define RFOR(i , n) for(i = n; i >= 0; i--)
#define tr(it , c) for(typeof(c.begin()) it = c.begin() ; it != c.end(); it++)

typedef struct node {
	int value;
	struct node *left;
	struct node *right;
	struct node *par;
}node;

vector <int>b;
vector <int>sarray;

void bitrep(int a) {
	int i = 0;
	while(a != 0) {
	b.PB(a % 2);
	a = a / 2;
	}
}

int height(node* root)
{
   if (root==NULL)
       return 0;
   else
   {
     /* compute the height of each subtree */
     int lheight = height(root->left);
     int rheight = height(root->right);
 
     /* use the larger one */
     if (lheight > rheight)
         return(lheight+1);
     else return(rheight+1);
   }
} 
node *build_heap(node *root) {
	//printf("%d  ", p->value);
	node *ptmp = root;
	node *p;
	int i;
	int size = b.size();
	RFOR(i , size-2){
	p = ptmp;
	if(b[i] == 0)
	ptmp = ptmp->left;
	else
	ptmp = ptmp->right;
	}
 
		while(ptmp->par != NULL) {
			if(ptmp->par->value > ptmp->value) {
			 int t;
 
			 t = ptmp->par->value;
			 ptmp->par->value = ptmp->value;
			 ptmp->value = t;
 
			 ptmp = ptmp->par;
			}
			else break;
		}
 
return root;
}

										
node *insert (node *root , int t) {
	node *tmp;
	tmp = (struct node *)malloc(sizeof(node));
	tmp->value = t;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->par = NULL;
	 
	
        if(root == NULL){
	root = tmp;
	 
	return root;
	}
	
	node *ptmp;
	node *p;
	ptmp = root;
		
	int size = b.size();
	int i;
	 
	RFOR(i , size-2){
	p = ptmp;
	if(b[i] == 0)
	ptmp = ptmp->left;
	else
	ptmp = ptmp->right;
	}

	tmp->par = p;
	
	if(p->left == NULL) 
	p->left = tmp;
	else 
	p->right = tmp;
	

return root;
}
void travel(node *root) {
	if(root == NULL)
	return ;
	printf("%d ", root->value);	
	travel(root->left);
	travel(root->right);
}	
	
void level_node(node* root, int level)
{
  if(root == NULL)
    return;
  if(level == 1)
    printf("%d ", root->value);
  else if (level > 1)
  {
    level_node(root->left, level-1);
    level_node(root->right, level-1);
  }
}
void level_order(node* root)
{
  int h = height(root);
  int i;
  for(i=1; i<=h; i++)
    level_node(root, i);
}
 
void swaps(struct node* a, struct node* b ) {
	int t = a->value;
	a->value = b->value;
	b->value = t;
} 
void down_balance (struct node * root) {

	struct node* temp;
	temp = root;

	if(temp->right!= NULL) {

	if(temp->value < temp->left->value && temp->value < temp->right->value) {
	return;
	}

	if((temp->left->value < temp->right->value) && (temp->left->value < temp->value)) {
	swaps(temp->left, temp);
	down_balance(temp->left);
	}

	else {
	swaps(temp->right, temp);
	down_balance(temp->right);
	}
	}

	if(temp->left != NULL) {

	if(temp->left->value < temp->value) {
	swaps(temp->left, temp);
	}
	}
return;	
}

node * del_root(node *root) {
	node *tmp;
	node *ptmp;
	
	tmp = root;
	ptmp = tmp;
	
	int i;
	int size = b.size();
	
	sarray.push_back(root->value);
	
        RFOR(i , size-2){
      	ptmp = tmp;
	if(b[i] == 0)
	tmp = tmp->left;
	else
	tmp = tmp->right;
	}
	swaps(tmp , root);
	
	tmp = NULL;
	free(tmp);
	
	if(b[0] == 0)
	ptmp->left = NULL;
	else
	ptmp->right = NULL;
	
	down_balance(root);
return root;
}
	

	

int main()
{
	int  n, i,t;
	node *root = NULL;
	scanf("%d", &n);
	 
	FOR(i , n) {
	b.clear();
	bitrep(i+1);
	cin>>t;
	root = insert(root,t);
	root = build_heap(root);
	}
	
	//travel(root);
	printf("\n");
	
	int h = height(root);
	cout<<"height of heap = "<<h<<endl;
	
	cout<<"Printing level order heap"<<endl;
	level_order(root);
	
return 0;
}
