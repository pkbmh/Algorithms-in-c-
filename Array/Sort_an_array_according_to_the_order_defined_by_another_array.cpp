#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])
#define tr(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)


void sort_according(int arr1[] , int size1 , int arr2[] , int size2) {
    map < int , int > *mymap = new map < int , int >;

    for(int i = 0; i < size1; i++) {
        if((*mymap)[arr1[i]] == NULL) {
            (*mymap)[arr1[i]] = 1;
        }
        else (*mymap)[arr1[i]]++;
    }
    for(int i = 0; i < size2; i++) {
        if((*mymap)[arr2[i]] != NULL) {
            int c = (*mymap)[arr2[i]];
            while(c--)
                cout << arr2[i] << " ";

            (*mymap)[arr2[i]] = NULL;
        }
    }
    sort(arr1 , arr1+size1);
    for(int  i = 0; i < size1; i++)
         if((*mymap)[arr1[i]] != NULL)
            cout << arr1[i] << " ";

    cout << endl;

}

int main()
{
    int arr1[] ={2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int arr2[] = {2, 1, 8, 3};

    int size1 = ARRAY_SIZE(arr1);
    int size2 = ARRAY_SIZE(arr2);

    sort_according(arr1 , size1 , arr2 , size2);


    cout << "Output array is " << endl;
    /*for(int i = 0; i < size1; i++)
        cout << arr1[i] << " ";
    cout << endl;
*/
return 0;
}
