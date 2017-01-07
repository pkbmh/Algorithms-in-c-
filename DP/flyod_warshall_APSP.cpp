#include <bits/stdc++.h>
using namespace std;
#define INF 99999

int v;

void floyd_warshall(vector< vector<int> >&mat) {
    
     for(int k = 0 ; k < v; k++) {
       
        for(int i = 0; i < v; i++) {
        
            for(int j = 0; j < v; j++) {
                
                 if(mat[i][k]+mat[k][j] < mat[i][j]) 
                    mat[i][j] = mat[i][k]+mat[k][j];
                     
            }
        }
    }
}
int main() {
    
    int s,d,i,j,k,w;
    cin >> v;
    vector< vector<int> >mat;
    mat.resize(v);
   
    for(i = 0; i < v; i++) {
       mat[i].resize(v);    
        for(j = 0; j < v; j++) {
            if(i == j)
            mat[i][j] = 0;
            else
            mat[i][j] = INF;
        }
    }
    
    while(1) {
        cin >> s >> d >> w;
        if(s == -1)
        break;
        
        mat[s][d] = w; 
    }
    floyd_warshall(mat);
    
    for(i = 0; i < v; i++) {
        for(j = 0; j < v; j++)  {
            if(mat[i][j] == INF)
            cout << "INF" << " ";
            else
            cout << mat[i][j] << "    ";
        }
        cout << endl;
    }
    
    return 0;
}
