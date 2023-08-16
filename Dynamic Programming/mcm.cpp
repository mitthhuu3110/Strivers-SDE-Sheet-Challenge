int helper(vector<int> &arr,int i,int j, vector<vector<int>> &dp){
    if(i == j){
        return 0;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int steps = INT_MAX;
    
    for(int k = i;k < j;k++){
        int one = helper(arr,i,k,dp);
        int two = helper(arr,k+1,j,dp);
        steps = min(steps,arr[i-1]*arr[k]*arr[j] + one + two);
    }
    
    return dp[i][j] = steps;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    int n = N;
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    return helper(arr,1,n-1,dp);
}
