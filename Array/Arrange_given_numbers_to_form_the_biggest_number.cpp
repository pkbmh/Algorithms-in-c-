#include <bits/stdc++.h>
using namespace std;

bool comp(string a , string b) {
    string ab = a.append(b);
    string ba = b.append(a);

    return (ab.compare(ba) > 0) ? 1 : 0;
}
int main()
{
    int n;
    cout << "Enter N" << endl;
    cin >> n;

    vector < string > str;
    string tmp;

    for(int  i = 0; i < n; i++){
        cin >> tmp;
        str.push_back(tmp);
    }

    sort(str.begin(), str.end(), comp);

    for(int i = 0; i < str.size(); i++)
        cout << str[i];
    cout << endl;

return 0;
}
