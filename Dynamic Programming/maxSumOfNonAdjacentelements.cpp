#include <bits/stdc++.h> 

int helper(int index, vector<int> &dp, vector<int> & nums){
    if(index == 0) return nums[index];
    if(index < 0) return 0;
    if(dp[index] != -1) return dp[index];
    int pick = nums[index] + helper(index - 2, dp, nums);
    int nonpick = 0 + helper(index - 1, dp, nums);
    return dp[index]  = max(pick, nonpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    /*susequence -> you have to write the code for recursion
    how do you identify for dp - > need to see for the subproblems
    */
    int n = nums.size();
    vector<int> dp(n, -1);
    return helper(n-1, dp, nums);
}
