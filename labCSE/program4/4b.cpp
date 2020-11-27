#include <iostream>

using namespace std;

void createHeap(int arr[], int n, int i)
{
    int biggest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[biggest])
        biggest = left;

    if (right < n && arr[right] > arr[biggest])
        biggest = right;

    if (biggest != i)
    {
        swap(arr[i], arr[biggest]);

        createHeap(arr, n, biggest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        createHeap(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        createHeap(arr, i, 0);
    }
}

void displayValues(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = {10, 15, 19, 75, 32, 23, 43, 11, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "The Array after heap sorting is : ";
    displayValues(arr, n);
}