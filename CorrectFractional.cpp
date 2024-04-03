#include <bits/stdc++.h>

using namespace std;

struct Product
{
    int weight;
    int profit;
    double unique_profit;
};


bool cmp(Product a, Product b){
    return a.unique_profit> b.unique_profit;
}

double fractionalKnapsack(Product arr[], int n, int w){

    int total = 0;
    for(int i = 0; i<n;i++){
        arr[i].unique_profit = double(arr[i].profit) / arr[i].weight;


    }

    sort(arr, arr+n, cmp);


    for(int i=0; i<n;i++){
        if(arr[i].weight<=w){
            total = total + arr[i].profit;
            w-= arr[i].weight;


        }
        else{
            total = total + arr[i].unique_profit * w;
            break;
        }

    }

    return total;


}




int main()
{
    int W = 15;
    int n = 3;

    int p[] = {200000, 100000, 500000};
    int w[] = {5, 3, 20};

    Product prod[n];


    for(int i = 0;i<n;i++){
        prod[i].weight = w[i];
        prod[i].profit = p[i];


    }

    double ans = fractionalKnapsack(prod, n, W);
    cout<<ans<<endl;


}