#include <bits/stdc++.h>
using namespace std;

void print_common(int arr1[] , int size1 , int arr2[] , int size2 , int arr3[] , int size3) {
    int i , j , k;
    i = j = k = 0;

    while(i < size1 && j < size2 && k < size3) {
        if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            cout << arr1[i] << " ";
            i++;
            j++;
            k++;
        }
        else if(arr1[i] < arr2[j] && arr1[i] < arr3[k])
            i++;
        else if(arr2[j] < arr1[i] && arr2[j] < arr3[k])
            j++;
        else
            k++;
    }
}
int main()
{
    int arr1[] = {1, 5, 10, 20, 40, 80};
    int arr2[] = {6, 7, 20, 80, 100};
    int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    print_common(arr1 , size1 , arr2 , size2 , arr3 , size3);

return 0;
}
