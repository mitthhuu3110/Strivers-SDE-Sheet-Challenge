#include<bits/stdc++.h>
int helper(int ind, int W, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
    if(ind == 0){
        return ((int)(W/weight[0]))*profit[0];
    }
    if(dp[ind][W] != -1) return dp[ind][W];
    int nottake = 0 + helper(ind - 1, W, profit, weight, dp);
    int take = 0;
    if(weight[ind] <= W) take = profit[ind] + helper(ind, W - weight[ind], profit, weight, dp);
    return dp[ind][W] = max(take, nottake);
}


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int> (w + 1, -1));
    return helper(n-1, w, profit, weight, dp);
}
