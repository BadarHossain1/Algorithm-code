#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {52, 12, 14, 9, 8, 47, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The array before sorting" << endl;

    for (int i = 0; i < n; i++)
    {
         cout<<arr[i]<<endl;
    }

    // sorting starts here

    int temp, j;

    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && temp <= arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }

    cout << "Array After Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        // cout<<arr[i]<<endl;
    }

    // Selection sort

    int min;
    for(int i=0;i<n-1;i++){
        min = i;

        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }

        swap(arr[min], arr[i]);


    }

    for (int i = 0; i < n; i++)
    {
        // cout<<arr[i]<<endl;
    }





    //Bubble sort

    for(int i = 0; i<n;i++){
        int swaps = 0;

        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swaps = 1;
            }
        }
        if(swaps==0){
            break;
        }
    }
    // cout<<"Bubble sorted"<<endl;
    for (int i = 0; i < n; i++)
    {
        //  cout<<arr[i]<<endl;
    }






    




    return 0;
}
