class Solution {
public:
void solve(int i, set<vector<int>> &s, vector<int> nums, vector<int> ds) {
        if(i==nums.size()){
            s.insert(ds);
            return;
        }
        ds.push_back(nums[i]);
        solve(i+1,s,nums,ds);
        ds.pop_back();
        solve(i+1,s,nums,ds);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> ds;
        solve(0,s,nums,ds);
        for(auto i:s) {
            ans.push_back(i);
        }
        return ans;
    }
};



