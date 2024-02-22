// #include <stdio.h>
// #include <iostream>

// using namespace std;

// // insertion sort

// // int main(){

// //     int arr[] = {0,4,1,2,9,3,6};
// //     int temp;
// //     int j;

// //     int n = 7;

// //     for(int i=1;i<n;i++){
// //         temp = arr[i];
// //         j = i-1;
// //         while(j>=0 && temp<=arr[j]){
// //             arr[j+1] = arr[j];
// //             j--;
// //         }
// //         arr[j+1] = temp;
// //     }

// //     for(int i=0;i<n;i++){
// //         cout<<arr[i]<<endl;
// //     }

// //     return 0;
// // }

// // selection sort

// // int main()
// // {

// //     int j, min;
// //     int arr[] = {0, 4, 1, 2, 9, 3, 6};
// //     int size = 7;
    
// //     for(int i=0;i<size-1;i++){
// //         min = i;
// //         for(int j=i+1;j<size;j++){
// //             if(arr[j]<arr[min]){
// //                 min = j;
// //             }
// //         }
// //         int temp;
// //        temp = arr[i];
// //        arr[i] = arr[min];
// //        arr[min] = temp;
// //     }

// //     for(int i=0;i<size;i++){
// //         cout<<arr[i]<<endl;
// //      }
// // }


// //bubble sort

// int main()
// {

//     int j, min;
//     int arr[] = {0, 4, 1, 2, 9, 3, 6};
//     int size = 7;
    
//     for(int i=0;i<size-1;i++){
//         int swap = 0;
//         for(j=0;j<size-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 int temp;
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//                 swap = 1;

//             }
//         }
//         if(!swap){
//             break;
//         }
//     }

//     for(int i=0;i<size;i++){
//         cout<<arr[i]<<endl;
//      }
// }

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct Product{
    int weight;
    int profit;
    double unique_profit;



};

bool cmp(Product a, Product b)
{   return a.unique_profit>b.unique_profit;


}


int fractional_knapsack(Product product[], int n, int w){
    int total  = 0;
    //unique profit

    for(int i=0;i<n;i++){
        product[i].unique_profit = double(product[i].profit)/product[i].weight;

    }
    sort(product, product+n, cmp);

    for(int i=0;i<n;i++){
        if(product[i].weight<=w){
            w-=product[i].weight;
            total+= product[i].profit;
        }
        else{
            total+= product[i].profit * (w/product[i].weight);
            break;
        }
    }
    return total;


   
}

int main(){

    int n = 7;
    int w = 15;

    int profit[] = {10, 5, 15, 7, 6, 18, 3};
    int weight[] = { 2, 3, 5, 7, 1, 4, 1 };


    Product arr[n];

    for(int i=0;i<n;i++){
        arr[i].profit = profit[i];
        arr[i].weight = weight[i];

    }

    double ans = fractional_knapsack(arr, n, w);
    cout<<ans<<endl;





    return 0;
}