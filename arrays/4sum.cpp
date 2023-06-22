class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    
    vector<vector<int>> res;
    
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int low = j+1;
            int high = n-1;
            
           long long int find_target = ( long long )target-nums[i]-nums[j];
            while(low<high){
                if(nums[low]+nums[high] == find_target){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    
                    res.push_back(temp);
                    
                    while(low<high && nums[low]==nums[low+1]) low++;
                    while(high>low && nums[high]==nums[high-1])high--;
                    
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high]<find_target)
                {
                    low++;
                }
                else{
                    high--;
                }
            }
            
            while(j+1<n && nums[j]==nums[j+1])j++;
        }
         while(i+1<n && nums[i]==nums[i+1])i++;
    }
    return res;
}
};
