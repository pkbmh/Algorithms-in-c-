#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

typedef struct DAY{
    int sell;
    int buy;
}DAY;

void stock_buy(int arr[], int n) {

    DAY buy_sell[n/2+1];

    int i = 0;
    int c = 0;

    while(i < n) {
        while((i < n) && (arr[i+1] <= arr[i]))
            i++;
        if(i == n-1)
            break;

       // cout << " i " << i << endl;
        buy_sell[c].buy = i++;

        while((i < n) && arr[i] >= arr[i-1])
            i++;

        buy_sell[c].sell = i-1;

        c++;

    }
   if (c == 0)
        printf("There is no day when buying the stock will make profit\n");
    else
       for (int i = 0; i < c; i++)
          printf("Buy on day: %d\t Sell on day: %d\n", buy_sell[i].buy, buy_sell[i].sell);

}
int main()
{
    int arr[] = {100, 180, 260, 310, 40, 535, 695};
    int n = ARRAY_SIZE(arr);

    stock_buy(arr , n);

return 0;
}
