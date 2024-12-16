
#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)//time complexity=O(nlogn)
{
    int l = 2 * i + 1;//to know index of left child
    int r = 2 * i + 2;//to know index of right child
    int max = i;
    if (l<n && arr[l]>arr[max])
        max = l;
    if (r<n && arr[r]>arr[max])
        max = r;
    if (max != i)
    {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}
void buildHeap(int arr[], int n)//time complexity=O(n)
{
    for (int i = n / 2 - 1;i >= 0;i--)
        heapify(arr, n, i);
}
void heapsort(int arr[], int n)//time complexity=O(nlogn) 
{
    buildHeap(arr, n);
    for (int i = n - 1;i >= 0;i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void print(int arr[], int n)
{
    for (int i = 0;i < n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = { 90,10,40,70,5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    heapsort(arr, n);
    print(arr, n);
}

