// write a knapsack problem code using fractional knapsack where it finds profit and weight ratio

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item{
    int weight;
    int value;
};

bool compare(Item a, Item b){
    double r1 = (double)a.value/a.weight;
    double r2 = (double)b.value/b.weight;
    return r1>r2;
}

double fractionalKnapsack(int W, vector<Item> arr, int n){
    sort(arr.begin(), arr.end(), compare);
    int curWeight = 0;
    double finalValue = 0.0;
    for(int i=0; i<n; i++){
        if(curWeight + arr[i].weight <= W){
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else{
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain/arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main(){
    int W = 50;
    Item arr[] = {{10,60}, {20,100}, {30,120}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);
    return 0;
}