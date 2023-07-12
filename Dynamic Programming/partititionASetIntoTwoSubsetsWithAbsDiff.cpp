#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totSum = 0;
	for(int i = 0; i < n; i++){
		totSum += arr[i];
	}
	int k = totSum;
	vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
	for(int i = 0; i < n; i++){
		dp[i][0] = true;
	}
	if(arr[0] <= k) dp[0][arr[0]] = true;
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= k; j++){
			bool take = false;
			bool nottake = dp[i -1][j];
			if(arr[i] <= j) take = dp[i-1][j - arr[i]];
			dp[i][j] = take | nottake;
		}
	}
	int mini = 1e9;
	for(int j = 0; j <= totSum/2; j++){
		if(dp[n-1][j] == true){
			mini = min(mini, abs((totSum - j) - j));
		}
	}
	return mini;
}
