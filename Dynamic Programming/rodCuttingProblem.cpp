#include<bits/stdc++.h>
int helper(int ind, int N, vector<int> &price, vector<vector<int>> &dp){
	if(ind == 0){
		return N*price[0];
	}
	if(dp[ind][N] != -1) return dp[ind][N];
	int nottake = 0 + helper(ind-1, N, price, dp);
	int take = INT_MIN;
	int rodlength = 1 + ind;
	if(rodlength <= N) take = price[ind] + helper(ind, N - rodlength, price, dp);
	return dp[ind][N] = max(take, nottake);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n+1, -1));
	return helper(n-1, n, price, dp);
}
