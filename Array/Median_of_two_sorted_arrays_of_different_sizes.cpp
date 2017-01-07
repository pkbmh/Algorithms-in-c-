#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

float median_of_2(int a , int b) {
    return ((a + b) / 2.0);
}
float median_of_3(int a , int b , int c) {
    return (a+b+c-max(a , max(b,c))-min(a , min(b,c)));
}
float median_of_4(int a , int b , int c , int d) {
    return ((a+b+c+d-max(a , max(b , max(c,d)))-min(a , min(b , min(c,d)))) / 2.0);
}

float find_median(int arr1[] , int size1 , int arr2[] , int size2) {
    if(size1 == 1) {
        if(size2 == 1)
            return median_of_2(arr1[0] , arr2[0]);
        if(size2 & 1)
            return median_of_2(arr2[size2/2] , median_of_3(arr1[0] , arr2[size2/2-1] , arr2[size2/2+1]));
        else
            return median_of_3(arr1[0] , arr2[size2/2] , arr2[size2/2-1]);
    }
    else if(size1 == 2) {
        if(size2 == 2)
            return median_of_4(arr1[0] , arr1[1] , arr2[0] , arr2[1]);

        if(size2 & 1)
            return median_of_3(arr2[size2/2] , max(arr1[0] , arr2[size2/2-1]) , min(arr1[1] , arr2[size2/2+1]));
        else
            return median_of_4(arr2[size2/2] , arr2[size2/2-1] , max(arr1[0] , arr2[size2/2-2]) , min(arr1[1] , arr2[size2/2+1]));
    }

    int index1 = (size1-1)/2;
    int index2 = (size2-1)/2;

    if(arr1[index1] <= arr2[index2])
        return find_median(arr1+index1 , size1/2+1 , arr2 , size2-index1);

    return find_median(arr1 , size1/2+1 , arr2+index1 , size2-index1);

}
int main()
{
    int arr1[] = {1,2};
    int arr2[] = {5,8,10};
    int size1 = ARRAY_SIZE(arr1);
    int size2 = ARRAY_SIZE(arr2);
    float median;

    if(size2 > size1)
        median = find_median(arr1 , size1 , arr2 , size2);
    else median = find_median(arr2 , size2 , arr1 , size1);

    cout << "Median is " << median << endl;


return 0;
}
