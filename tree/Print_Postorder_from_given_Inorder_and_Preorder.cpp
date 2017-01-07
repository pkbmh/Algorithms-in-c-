#include <bits/stdc++.h>
using namespace std;

int find_root(int in[] , int root , int n) {
    for(int i = 0; i < n; i++)
        if(root == in[i])
            return i;
    return -1;
}
void print_postorder(int in[] , int pre[] , int n) {

    int root = pre[0];
    int indx = find_root(in , root , n);

    if(indx != 0)
        print_postorder(in , pre+1 , indx);
    if(indx != n-1)
        print_postorder(in+indx+1 , pre+indx+1 , n-indx-1);

    cout << pre[0] << " ";
}
int main()
{
    int n;
    cout << "Number of total node " << endl;
    cin >> n;

    int in[n];
    int pre[n];

    cout << "Enter inorder " << endl;
    for(int i = 0; i < n; i++)
        cin >> in[i];

    cout << "Enter preorder" << endl;
    for(int i = 0; i < n; i++)
        cin >> pre[i];

    print_postorder(in , pre , n);

return 0;
}
