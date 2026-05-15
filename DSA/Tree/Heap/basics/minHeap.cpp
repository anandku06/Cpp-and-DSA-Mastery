#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[smallest] > arr[l])
        smallest = l;

    if (r < size && arr[smallest] > arr[r])
        smallest = r;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, size, smallest);
    }
}

void insertion(int arr[], int &size, int value)
{
    if (size == 0)
    {
        arr[0] = value;
        size++;
    }

    else
    {
        arr[size] = value;
        size++;

        int i = size - 1;

        while (i > 0 && arr[i] < arr[(i - 1) / 2])
        {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
}