#include <bits/stdc++.h>
using namespace std;

char char_map[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

string id_to_url(unsigned int id) {
    string url;

    while(id) {
        url.push_back(char_map[id%62]);
        id = id / 62;
    }
    reverse(url.begin() , url.end());
    return url;
}

unsigned int url_to_id(string url) {
    unsigned int id = 0;

    for(int i = 0; i < url.length(); i++) {
        if(url[i] >= 'a' && url[i] <= 'z')
            id = id * 62 + url[i]-'a';
        if(url[i] >= 'A' && url[i] <= 'Z')
            id = id * 62 + url[i] - 'A' + 26;
        if(url[i] >= '0' && url[i] <= '9')
            id = id * 62 + url[i] - '0' + 52;
    }
    return id;
}
int main()
{
    unsigned int id = 12345;
    string url = id_to_url(id);
    cout << "URL for id = "<< id << " is = " << url << endl;
    id = url_to_id(url);
    cout << " id for url = " << url << " is = " << id << endl;
return 0;
}
