#include<bits/stdc++.h>
long helper(int ind, int buy, long *values, int n, vector<vector<long>> &dp){
    if(ind == n) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];
    long profit = 0;

    if(buy){
        profit = max(-values[ind] + helper(ind+1, 0, values, n, dp), 0 + helper(ind+1, 1, values, n, dp));
    }else{
        profit = max(values[ind] + helper(ind+1, 1, values, n, dp), 0 + helper(ind+1, 0, values, n, dp));
    }
    return dp[ind][buy] = profit;
}


long getMaximumProfit(long *values, int n){
    //Write your code here
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return helper(0, 1, values, n, dp);
}
