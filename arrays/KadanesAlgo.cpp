class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int sum=0;
    int res= INT_MIN;
    for(auto i:nums){
        sum +=i;
        res=max(sum, res);
        if(sum<0)
            sum=0;
    }
    return res;
    }
};
