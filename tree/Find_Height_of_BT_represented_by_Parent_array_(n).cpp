#include <bits/stdc++.h>
using namespace std;

void fill_depth(int parent[] , int depth[] , int r ,int n) {
    if(r >= n)
        return;

    if(depth[r] != 0)
        return;
    if(parent[r] == -1) {
        depth[r] = 1;
        return;
    }

    if(depth[parent[r]] != 0)
        depth[r] = depth[parent[r]] + 1;
    else
        fill_depth(parent , depth , parent[r] , n);

    depth[r] = depth[parent[r]] + 1;
}
int find_height(int parent[] , int n) {

    int depth[n];
    for(int i = 0; i < n; i++)
        depth[i] = 0;

    for(int i = 0; i < n; i++)
        fill_depth(parent , depth , i , n);

    int md = 0;
    for(int i = 0; i < n; i++)
        md = max(md , depth[i]);

    return md;

}
int main()
{
    int n;
     cout << "Enter total node " << endl;
    cin >> n;

    cout << "Enter parent array" << endl;
    int parent[n];
    int r;

    for(int i = 0; i < n; i++) {
        cin >> parent[i];
        if(parent[i] == -1)
            r = i;
    }

    int h = find_height(parent , n);
    cout << "Height of tree is " << h << endl;

return 0;
}
