#include<bits/stdc++.h>
int helper(int ind, int buy, int fee, vector<int> &prices, int n, vector<vector<int>> &dp){
    if(ind >= n) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];

    if(buy == 1){
        return dp[ind][buy] =  max(-prices[ind] + helper(ind+1, 0, fee, prices, n, dp), 0 + helper(ind+1, 1, fee, prices, n, dp));
    }
    return dp[ind][buy] = max(prices[ind] -fee + helper(ind+1, 1, fee, prices, n, dp), 0 + helper(ind+1, 0, fee, prices, n, dp));
}

int maximumProfit(vector<int> &prices, int n, int fee)
{
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(2, -1));
    return helper(0, 1, fee, prices, n, dp);
}
