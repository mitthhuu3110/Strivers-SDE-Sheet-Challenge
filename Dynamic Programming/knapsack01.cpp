#include <bits/stdc++.h> 
int helper(int ind, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp){
	if(ind == 0){
		if(weight[0] <= maxWeight) return value[0];
		return 0;
	}
	if(dp[ind][maxWeight] != -1) return dp[ind][maxWeight];
	int nottake = 0 + helper(ind-1, maxWeight, weight, value, dp);
	int take = INT_MIN;
	if(weight[ind] <= maxWeight) take = value[ind] + helper(ind - 1, maxWeight - weight[ind], weight, value, dp);
	return dp[ind][maxWeight] = max(take, nottake);
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// Write your code here
	vector<vector<int>> dp(n, vector<int> (maxWeight + 1, -1));
	return helper(n-1, maxWeight, weight, value, dp);
}
