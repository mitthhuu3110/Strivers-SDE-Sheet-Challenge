bool helper(int n, int k, vector<int> &arr, vector<vector<int>> &dp){
    if(k == 0) return true;
    if(n == 0) return (arr[0] == k);
    if(dp[n][k] != -1) return dp[n][k];

    bool ntake = helper(n-1, k, arr, dp);
    bool take = false;
    if(arr[n] <= k){
        take = helper(n-1, k - arr[n], arr, dp);
    }
    return dp[n][k] = (take || ntake);
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return helper(n-1, k, arr, dp);
}
bool canPartition(vector<int>& arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    if(sum % 2) return false;
    int target = sum/2;
    return subsetSumToK(n, target, arr);
}
