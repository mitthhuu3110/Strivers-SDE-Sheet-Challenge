int helper(int index, vector<int> &houses, vector<int> &dp){
	if(index == 0) return houses[index];
	if(index < 0) return 0;
	if(dp[index] != -1) return dp[index];
	int pick = houses[index] + helper(index -2, houses, dp);
	int nonpick = helper(index -1, houses, dp);
	return dp[index] = max(pick, nonpick); 
}



int maxMoneyLooted(vector<int> &houses, int n)
{
	/*
		Write your code here.
		Don't write main().
	 	Don't take input, it is passed as function argument.
	 	Don't print output.
	 	Taking input and printing output is handled automatically.
	*/
	vector<int> dp(n+1, -1);
	return helper(n-1, houses, dp);
}
