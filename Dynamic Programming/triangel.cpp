#include <bits/stdc++.h> 

int helper(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
	if(i == n-1) return triangle[n-1][j];
	if(dp[i][j] != -1) return dp[i][j];
	int down = triangle[i][j] + helper(i+1, j, triangle, n, dp);
	int diag = triangle[i][j] + helper(i+1, j+1, triangle, n, dp);
	return dp[i][j] = min(down, diag);
}


int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> dp(n, vector<int> (n, -1));
	return helper(0, 0, triangle, n, dp);
}
