#include <stdio.h>
#include <iostream>

using namespace std;


void mergee(int A[], int lb, int mid, int ub){
    int i = lb;
    int j = mid+1;
    int k = lb;

    int B[ub+1];
    while(i<=mid && j<=ub){
        if(A[i]<=A[j]){
            B[k] = A[i];
            i++;
        }
        else{
            B[k] = A[j];
            j++;
        }
        k++;
    }

    if(i>mid){
        while(j<=ub){
            B[k] = A[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            B[k] = A[i];
            i++;
            k++;
        }
    }
}


void mergesort(int A[], int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergesort(A,lb,mid);
        mergesort(A,mid+1,ub);
        mergee(A,lb,mid,ub);
    }
}


int main(){
    int A[] = {10,14,33,35,42,44,19,26,27,31};
    int lb = 0;
    int ub = 9;
    mergesort(A,lb,ub);
    for(int i=0; i<10; i++){
        cout << A[i] << " ";
    }
    return 0;
}