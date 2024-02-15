#include <iostream>

using namespace std;

void printMerge(int arr[],int lb ,int ub)
{
    // Printing the sorted array
    cout << "Sorted array: "<<endl;
    for (int p = lb; p <= ub; p++) {
        cout << arr[p] << " ";
    }
    cout << endl;
}


void merge(int arr[], int lb,int mid,int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int arr2[ub + 1];

    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            arr2[k] = arr[i];
            i++;
        }
        else
        {
            arr2[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while (j <= ub)
        {
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            arr2[k] = arr[i];
            i++;
            k++;
        }
    }

    // Copying the arr2 to the original array
    for (int i = lb; i <= ub; i++)
    {
        arr[i] = arr2[i];
    }
}


void mergeSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = lb+(ub-lb) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main()
{

    int arr[] = {57, 1, 65, 10, 5, 6, 3, 2, 1};

    int lb = 0;
    int ub = sizeof(arr)/sizeof(arr[0])-1;

    cout << "The array before sorting is :" << endl;
    for (int i = 0; i <= ub; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    mergeSort(arr, lb, ub);

    printMerge(arr,lb,ub);

    return 0;
}