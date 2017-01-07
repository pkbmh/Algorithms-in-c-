#include <iostream>
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
void swap(int *a, int *b)
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
void merge(int a[], int p, int q, int r)
{
int i,j,k;
int n1 = q - p + 1;
int n2 = r - q;
int l[n1],m[n2];
// storing 2 divided arrays
for(i = 0; i < n1; i++)
l[i] = a[p + i];
for(i = 0; i < n2; i++)
m[i] = a[q + i +1];
//merging the arrays in sorted order
i = 0;
j = 0;
k = p;
while(i < n1 && j < n2) {
if(l[i] < m[j]) {
a[k] = l[i];
i++;
}
else {
a[k] = m[j];
j++;
}
k++;
}
while(i < n1) {
a[k++] = l[i++];
}
while(j < n2) {
a[k++] = m[j++];
}
}
void mergeSort(int a[], int p, int r, int x)
{
int i;
if(p < r) {
int size = r - p + 1;
if (size <= x){
int k = 0;
int arr[size];
for(i = p; i <= r; i++)
arr[k++] = a[i];
heapsort(a, size);
k = 0;
for( i = p; i <= r; i++)
a[i] = arr[k++];
}
else {
int q = (p + r) / 2;
mergeSort(a, p, q, x);
mergeSort(a, q + 1, r, x);
merge(a, p, q, r);
}
}
}
void printArray(int a[], int n)
{
int i;
for(i = 0; i < n; i++) {
cout << a[i] << " ";
}
cout << endl;
}
int main()
{
int n,x;
cout << "Enter Size" << endl;
cin >> n;
cout << "Enter value of x: " << endl;
cin >> x;
int a[n];
int i;
cout << "Enter " << n << " Numbers:" << endl;
for(i = 0; i < n; i++) {
cin >> a[i];
}
mergeSort(a, 0, n - 1, x);
cout << "Sorted Array:" << endl;
printArray(a, n);
}
