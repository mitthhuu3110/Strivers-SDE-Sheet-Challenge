#include <bits/stdc++.h> 
int helper(int ind, int target, vector<int> &num, vector<vector<int>> &dp){
    if(ind == 0){
        if(target%num[0] == 0) return target/num[0];
        return 1e9;
    }
    if(dp[ind][target] != -1) return dp[ind][target];
    int nottake = 0 + helper(ind - 1, target, num, dp);
    int take = INT_MAX;
    if(num[ind] <= target) take = 1 + helper(ind, target - num[ind], num, dp);
    return dp[ind][target] = min(take, nottake);
}
int minimumElements(vector<int> &num, int x){
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (x+1, -1));
    int res = helper(n-1, x, num, dp);
    if(res >= 1e9) return -1;
    return res;
}
