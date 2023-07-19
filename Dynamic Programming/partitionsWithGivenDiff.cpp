#include <bits/stdc++.h> 
int mod = (int)(1e9+7);
int helper(int ind, int sum, vector<int> &num, vector<vector<int>> &dp){
    if(ind == 0){
        if(sum == 0 && num[0] == 0) return 2;
        if(sum == 0 || sum == num[0]) return 1;
        return 0;
    }
    if(dp[ind][sum] != -1) return dp[ind][sum];
    int nottake = helper(ind - 1, sum, num, dp);
    int take = 0;
    if(num[ind] <= sum) take = helper(ind - 1, sum - num[ind], num, dp);
    return dp[ind][sum] = (take + nottake)%mod;
}

int findWays(vector<int> & num, int tar){
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, -1));
    return helper(n-1, tar, num, dp);
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totSum = 0;
    for(auto &it: arr) totSum += it;
    if((totSum-d)%2 || (totSum - d) < 0) return false;
    return findWays(arr, (totSum-d)/2);
}


