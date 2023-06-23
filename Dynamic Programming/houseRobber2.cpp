#include <bits/stdc++.h> 

int helper(vector<int> & nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i = 1; i < n; i++){
        int take = nums[i];
        if(i > 1) take += prev2;
        int nottake = prev;
        int cur = max(take, nottake);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}


long long int houseRobber(vector<int>& valueInHouse){
    // Write your code here.
    vector<int> v1, v2;
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    for(int i = 0; i < n; i++){
        if(i != 0){
            v1.push_back(valueInHouse[i]);
        }
        if(i != n-1){
            v2.push_back(valueInHouse[i]);
        }
    }
    return max(helper(v1), helper(v2));

}
