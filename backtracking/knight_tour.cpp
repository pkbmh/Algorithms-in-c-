#include <bits/stdc++.h>
using namespace std;

#define N 8

int solution[N][N];

bool in_grid(int x , int y) {
    if(x >= 0 && x < N && y >= 0 && y < N && solution[x][y] == -1)
        return true;
    
    return false;
}

bool find_solution(int x , int y , int movei , int next_x[] , int next_y[]) {
        int i,nx , ny;
        if(movei == N*N)
        return true;
        
        for(i = 0; i < N; i++) {
        nx = x + next_x[i];
        ny = y + next_y[i];
        
        if(in_grid(nx , ny)) {
            solution[nx][ny] = movei;
            if(find_solution(nx , ny , movei+1 , next_x , next_y))
            return true;
            else
            solution[nx][ny] = -1; //backtrack
        }
    }
    return false;
}
void print_solution() {
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << solution[i][j] << " ";
        
        cout << endl;
    }
}
int main() {
    int next_x[N] = {-2 , -1 , 1 , 2 , 2 , 1 , -1 , -2};
    int next_y[N] = {1 , 2 , 2 , 1 , -1 , -2 , -2 , -1};
    int i,j,x,y;
    
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            solution[i][j] = -1;
            
    solution[0][0] = 0; // starting
    x = y = 0;
    
    if(find_solution(x , y , 1 , next_x , next_y))
        print_solution();
    else
    cout << "solution not exits" <<endl;
    
return 0;
}
