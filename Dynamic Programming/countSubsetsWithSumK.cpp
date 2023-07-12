int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>>dp(n, vector<int>(tar+1, 0));
    for(int i= 0; i< n; i++){
        dp[i][0] = true;
    }
    if(num[0] <= tar){
        dp[0][num[0]] = true;
    }
    if(num[0] == 0){
        dp[0][0] = 2;
    }
    for(int ind = 1; ind<n; ind++){
        for(int sum = 0; sum<= tar; sum++){
            int notpick = dp[ind-1][sum];
            int pick = 0;
            if(num[ind] <= sum){
                pick = dp[ind-1][sum - num[ind]];
            }
            dp[ind][sum] = notpick + pick;
        }
    }
 
    return dp[n-1][tar];
}
