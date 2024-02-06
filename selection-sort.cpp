#include <stdio.h>
#include <iostream>
using namespace std;



void selectionSort(int array[], int size)
{
    int i, j, minn;
    for (i = 0; i < size - 1; i++)
    {
        minn = i; // get index of minimum data
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[minn])
                minn = j;
        }
        // placing in correct position
        int temp;
        temp = array[i];
        array[i] = array[minn];
        array[minn] = temp;
    }
}

int main()
{
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);
    selectionSort(data, size);
    printf("Sorted array in Acsending Order:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", data[i]);
    }
    return 0;
}