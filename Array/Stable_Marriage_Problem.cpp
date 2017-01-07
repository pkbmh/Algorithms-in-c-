#include <bits/stdc++.h>
using namespace std;
const int n = 4;

void print_married_couple(int mwomen[]) {
    cout << "Men   :  Women" << endl;
    for(int i = 0; i < n; i++)
        cout << (mwomen[i]+1) << "         " << (i+1) << endl;
}
bool prefer_over_current(int cwomen ,int cmen ,int cpartner , int women_choice[][n]) {
    for(int i = 0; i < n; i++) {
        if(women_choice[cwomen][i] == cmen)
            return true;
        if(women_choice[cwomen][i] == cpartner)
            return false;
    }
}
void stable_marriage(int men_choice[][n] , int women_choice[][n]) {
     bool mmen[n];
     int mwomen[n];
     for(int i = 0; i < n; i++){
        mmen[i] = false;
        mwomen[i] = -1;
    }

     int free_count = n;
     int cmen,cwomen;
     while(free_count > 0) {

        for(cmen = 0; cmen < n; cmen++)
            if(mmen[cmen] == false)
                break;
        for(int i  = 0; i < n; i++) {
            cwomen = men_choice[cmen][i];
            if(mwomen[cwomen] == -1) {
                mwomen[cwomen] = cmen;
                mmen[cmen] = true;
                free_count--;
                break;
            }
            else {
                int cpartner = mwomen[cwomen];
                if(prefer_over_current(cwomen , cmen , cpartner , women_choice) == true) {
                    mwomen[cwomen] = cmen;
                    mmen[cmen] = true;
                    mmen[cpartner] = false;
                }
            }
        }
     }

     print_married_couple(mwomen);
}
int main()
{
    int men_choice[][n] = {{3,1,2,0} , {1,0,2,3} , {0,1,2,3},{0,1,2,3}};
    int women_choice[][n] = {{0,1,2,3},{0,1,2,3},{0,1,2,3},{0,1,2,3}};


    stable_marriage(men_choice , women_choice);

return 0;
}
