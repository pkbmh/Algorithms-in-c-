#include <bits/stdc++.h>
using namespace std;

#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

void print_sentance(list <string> *word_list ,int wl ,  int n , string sentence) {
    if(n == wl){
        cout << sentence << endl;
        return;
    }
    tr(word_list[wl] , it) {
        print_sentance(word_list , wl+1 , n , (sentence+ " " +(*it)));
    }
}
int main()
{
   list <string> *word_list = new list<string>[3];
    word_list[0].push_back("you");
    word_list[0].push_back("we");
    word_list[1].push_back("have");
    word_list[1].push_back("are");
    word_list[2].push_back("sleep");
    word_list[2].push_back("eat");
    word_list[2].push_back("drink");

    print_sentance(word_list ,0 , 3 , "");

return 0;
}
