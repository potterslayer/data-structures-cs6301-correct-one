#include <iostream>
using namespace std;

int binarySearch(int arr[], int first, int last, int element)
{
    if (last >= first)
    {
        int mid = first + (last - first) / 2;
        if (arr[mid] == element)
            return mid;
        if (arr[mid] > element)
            return binarySearch(arr, first, mid - 1, element);
        return binarySearch(arr, mid + 1, last, element);
    }
    return -1;
}

int elementsearch(int arr[], int element)
{
    // defining initial and end of array..
    int first = 0, last = 1;

    int val = arr[0];

    while (val < element)
    {
        first = last;
        last = last * 2;
        val = arr[last];
    }

    return binarySearch(arr, first, last, element);
}

int main()
{

    int n;
    cin >> n;

    int arr[10000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // taking input to be found..

    int element;
    cin >> element;

    

    elementsearch(arr, element);

    int ans = elementsearch(arr, element);
    if (ans == -1)
        cout << "no such element exist ";
    else
        cout << "the index at which this element is present is : " << ans;
    return 0;
}