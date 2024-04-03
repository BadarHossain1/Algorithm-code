#include <bits/stdc++.h>

using namespace std;


int knapsack(int profit[], int weight[], int n, int W){

    int dp[n+1][W+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(weight[i-1] <=j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]]+profit[i-1]);

            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}


int main(){



    int W = 5;

    int p[]= {4,3,6,5};
    int w[]={3,2,5,4};

    int n = sizeof(p)/sizeof(p[0]);

    int ans = knapsack(p,w,n,W);
    cout<<ans<<endl;

}