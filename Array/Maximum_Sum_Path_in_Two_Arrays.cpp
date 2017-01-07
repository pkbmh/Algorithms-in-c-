#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

int max_path_sum(int arr1[] , int size1 , int arr2[] , int size2) {
    int i,j;
    i = j = 0;
    int sum1,sum2;
    int sum = 0;
    while(i < size1 && j < size1) {
        sum1 = sum2 = 0;
        while(i < size1 && j < size2 && arr1[i] != arr2[j]){
            if(arr1[i] > arr2[j]) {
                sum2 += arr2[j];
                j++;
            }
            else{
                sum1 += arr1[i];
                i++;
            }
        }
        sum1 += arr1[i];
        sum2 += arr2[j];

        i++;
        j++;
        sum += (sum1 > sum2) ? sum1 : sum2;
    }
    sum1 = sum2 = 0;
    while(i < size1) {
        sum += arr1[i];
        i++;
    }
    while(j < size2){
        sum += arr2[j];
        j++;
    }

    return sum;
}
int main()
{
    int arr1[] = {2, 3, 7, 10, 12};
    int arr2[] = {1, 5, 7, 8};
    int size1 = ARRAY_SIZE(arr1);
    int size2 = ARRAY_SIZE(arr2);

    int path_sum = max_path_sum(arr1 , size1 , arr2 , size2);
    cout << "Maximum path sum is " << path_sum << endl;

return 0;
}
