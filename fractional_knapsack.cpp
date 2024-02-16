#include <iostream>
#include <algorithm>

using namespace std;

struct Product{
    int weight;
    int profit;
    double unique_profit;
};

bool cmp(Product a, Product b){
    return a.unique_profit > b.unique_profit;
}

double fractional_knapsack(Product arr[], int n, int W){
    int total = 0;

    for(int i=0; i<n; i++){
        arr[i].unique_profit = double(arr[i].profit) / arr[i].weight;
    }

    sort(arr, arr+n, cmp);

    for(int i=0; i<n; i++){
        if(arr[i].weight <= W){
            W -= arr[i].weight;
            total += arr[i].profit;
        }
        else{
            total += arr[i].unique_profit * (W / arr[i].weight);
            break;
        }
    }
    return total;
}

int main(){
    int n = 3;
    int W = 50;

    int p[] = {200000, 100000, 500000};
    int w[] = {5, 3, 20};


    Product prod[n];

    for(int i=0; i<n; i++){
        prod[i].profit = p[i];
        prod[i].weight = w[i];
    }

    double ans = fractional_knapsack(prod, n , W);
    cout << "The Maximum profit is "<< ans << endl;
    return 0;
}
