#include <bits/stdc++.h>

using namespace std;


int main(){

    int coins[] = {1,3,5};
    int amount = 8;

    int n = sizeof(coins)/sizeof(coins[0]);


    int dp[n+1][amount+1];

    for(int i=0;i<=n;i++){
        for(int j = 0;j<=amount;j++){
            if(i==0 && j==0){
                dp[i][j] = 1;

            }
            else if(i==0){
                dp[i][j] = 0;
            }
            else if(coins[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }
    }

    cout<<dp[n][amount]<<endl;
}