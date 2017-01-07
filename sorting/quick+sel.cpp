#include<iostream>
using namespace std;
void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}
void selection(int a[], int l, int h)
{
int i,j;
int pos;
for(i = l; i < h; i++) {
pos = i;
for(j = i + 1; j < h + 1; j++) {
if (a[j] < a[pos])
pos = j;
}
swap(&a[pos], &a[i]);
}
}
int partition (int arr[], int l, int h)
{
int x = arr[h]; // pivot
int i = (l - 1); // Index of smaller element
for (int j = l; j <= h- 1; j++)
{
if (arr[j] <= x)
{
i++; // increment index of smaller element
swap(&arr[i], &arr[j]); // Swap current element with index
}
}
swap(&arr[i + 1], &arr[h]);
return (i + 1);
}
void quickSort(int arr[], int l, int h, int x)
{
if (l < h)
{
int size = h - l + 1;
if(size <= x)//if size of array less than x then selection sort
selection(arr, l, h);
else {
int p = partition(arr, l, h); /* Partitioning index */
quickSort(arr, l, p - 1,x);
quickSort(arr, p + 1, h,x);
}
}
}
void printArray(int arr[], int size)
{
int i;
for (i=0; i < size; i++)
cout<< arr[i] << " ";
cout << endl;
}
int main()
{
int arr[] = {108, 7, 8, 999, 1, 5, 111, 101, 2, 4, 3};
int n = sizeof(arr)/sizeof(arr[0]);
quickSort(arr, 0, n-1, 2);
cout << "Sorted array: \n";
printArray(arr, n);
return 0;
}
