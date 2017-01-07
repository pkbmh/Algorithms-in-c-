#include <bits/stdc++.h>
using namespace std;

int find_customer(int n , char *str) {
    int cust = 0;
    bool visited[26];
    memset(visited , false , sizeof(visited));
    int count = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(visited[str[i]-'A'] == false && cust < n) {
          //  cout << " in " << str[i] << endl;
            visited[str[i]-'A'] = true;
            cust++;
        }
        else if(visited[str[i]-'A'] == true) {
           // cout << " out " << str[i] << endl;
            cust--;
            visited[str[i]-'A'] = false;
        }
        else {
            //cout << str[i] << " " ;
            count++;
            i++;
        }
    }
    cout << endl;
    return count;
}
int main()
{
   // int n = 3; char *str = "GACCBDDBAGEE"; // 1
   //int n = 3; char *str = "GACCBGDDBAEE"; // 0
    int n = 1; char *str = "ABCBCADEED"; // 3
    //int n = 1; char *str = "ABCBCA"; // 2
    //int n = 2; char *str = "ABBAJJKZKZ"; // 0

    int res = find_customer(n , str);
    cout << "Customer who could not get computer is : "<< res << endl;
return 0;
}
