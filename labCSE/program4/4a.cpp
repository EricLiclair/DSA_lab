#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &v, int initial, int final)
{
    if (initial >= final)
    {
        return initial;
    }
    int pivot = v[final];
    int i = initial;
    for (int j = initial; j < final; j++)
    {
        if (v[j] <= pivot)
        {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
        }
    }
    v[final] = v[i];
    v[i] = pivot;
    return i;
}

void quickSortMethod(vector<int> &v, int initial, int final)
{
    if (initial >= final)
        return;

    int p = partition(v, initial, final);
    quickSortMethod(v, initial, p - 1);
    quickSortMethod(v, p + 1, final);
}

int binarySearchMethod(vector<int> v, int initial, int final, int key)
{
    int mid = (initial + final) / 2;
    if (initial >= final - 1)
    {
        if (v[mid] != key)
            return -1;
        else
            return mid;
    }
    int i;
    if (key > v[mid])
        i = binarySearchMethod(v, mid, final, key);
    else if (key < v[mid])
        i = binarySearchMethod(v, initial, mid, key);
    else if (key == v[mid])
        i = mid;

    return i;
}

int linear_search(vector<int> v, int key)
{
    int j = 0;
    for (int i : v)
    {
        if (key == i)
            return j;
        j++;
    }
    return -1;
}

int main()
{
    vector<int> dataElement{2, 4, 1, 0, 3, 6, 8, 2, 41, 6, 3, 45, 6, 7, 100};

    quickSortMethod(dataElement, 0, dataElement.size() - 1);
    for (int i : dataElement)
        cout << i << "\t";
    cout << endl;

    cout << "(using linear search) Index of data Element 41 the first time is: " << linear_search(dataElement, 41) << endl;
    cout << "(using binary search) index of data element 100 the first time is: " << binarySearchMethod(dataElement, 0, dataElement.size(), 100) << endl;
}