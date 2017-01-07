#include<iostream>
using namespace std;
int left(int i)
{
//left node
return (2 * i);
}
int right(int i)
{
//right node
return (2 * i + 1);
}
void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}
void max_heapify(int a[], int i, int heap_size)
{
int l = left(i);
int r = right(i);
int largest;
//determine the largest among a[left],a[right] and a[i]
if (l < heap_size && a[l] > a[i]) {
largest = l;
}
else {
largest = i;
}
if(r < heap_size && a[r] > a[largest]) {
largest = r;
}
//If a[i] is not largest then we need to max-heapify otherwise terminate
if(largest != i) {
swap(&a[i],&a[largest]);
max_heapify(a, largest, heap_size);
}
}
void build_max_heap(int a[], int n)
{
//to convert the array into a max heap
int i;
int heap_size = n;
for(i = n / 2 ; i >= 0; i--)
max_heapify(a, i, heap_size);
}
void heapsort(int a[], int n)
{
int i;
int heap_size = n;
build_max_heap(a, n);//we build the array into a heap
//exchange the top element of the heap with the last element and then heapify again after decreasing the heap size by 1
for(i = n - 1; i > 0; i --) {
swap(&a[0],&a[i]);
heap_size--;
max_heapify(a, 0, heap_size);
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
int i;
if (l < h)
{
int size = h - l + 1;
if (size <= x){
int k = 0;
int a[size];
for(i = l; i <= h; i++)
a[k++] = arr[i];
heapsort(a, size);
k = 0;
for( i = l; i <= h; i++)
arr[i] = a[k++];
}
else {
int p = partition(arr, l, h); /* Partitioning index */
quickSort(arr, l, p - 1, x);
quickSort(arr, p + 1, h, x);
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
int arr[] = {10, 7, 8, 9, 1, 5, 2, 3, 21};
int n = sizeof(arr)/sizeof(arr[0]);
quickSort(arr, 0, n-1, 5);
cout << "Sorted array: \n";
printArray(arr, n);
return 0;
}
