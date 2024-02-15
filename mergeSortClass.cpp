#include <iostream>
using namespace std;

int a[10] ={10,14,33,35,42,44,19,26,27,31};
int b[10];
int n = 10;



// split in half  [10 14 33 35 42]   [44 19 26 27 31]

// [10 14 33]         35 42          44 19 26         27 31

// [10 14]     33     35    42       19 44     26     27 31

// 10     14     33 


void mergee(int low, int mid, int high){
    int i,l1,l2;
    
    for(l1=low, l2=mid+1, i=low; l1<=mid, 12<=high; i++){
        if(a[l1]<a[l2]){
            b[i] = a[l1];
            l1++;

        }
        else if(a[l2] <= a[l1]){
            b[i] = a[l2];
            l2++;

        }
    }

    while(l1<=mid){
        b[i++] = a[l1++];


    }

    while(l2<=high){
        b[i++] = a[l2++];
        

    }

    for(int i=low; i<=high; i++){
        a[i] = b[i];
        
    }

    
}


void mergesort(int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergesort(low, mid);
        mergesort(mid+1, high);
        mergee(low, mid, high);
    }
    else{
        return;
    }

}

int main(){
    mergesort(0, n);

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;


}

                      