#include <bits/stdc++.h>
int mod = 1000000007;

int helper(int nStairs, vector<int> &dp){
    if(nStairs == 0 || nStairs == 1) return 1;
    if(nStairs == 2) return 2;
    if(dp[nStairs] != -1) return dp[nStairs];
    return dp[nStairs] = (helper(nStairs-1, dp) + helper(nStairs-2, dp))%mod;
}

int countDistinctWays(int nStairs) {
    //  Write your code here.
    vector<int> dp(nStairs+1, -1);
    return helper(nStairs, dp);
}
