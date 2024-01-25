#include <stdio.h>
#include <iostream>

using namespace std;


void insert(int arr[], int n){
    int i, j, temp;

    for(i=1;i<n;i++ ){
        temp = arr[i];
        j = i-1;

        while(j>=0 && temp<=arr[j]){
            arr[j+1] = arr[j];
            j = j-1;

        }
        arr[j+1] = temp;

    }
}




int main(){
    //selection sort

    // complexity is n^2

    //space complexity is o(1) because the sorting happens in the array without taking an extra array or so.

    int arr[] = {12, 21 , 54, 20 , 10};

    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Before sorting the elements:\n");

    for(int i=0;i<size;i++){
        printf("%d \t",arr[i]);
    }

    insert(arr, size);
    printf("\n");
    for(int i=0;i<size;i++){
        printf("%d \t",arr[i]);
    }


}