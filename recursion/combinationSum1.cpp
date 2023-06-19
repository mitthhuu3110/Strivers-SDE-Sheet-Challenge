class Solution {
public:
    void helper(int index, int target, vector<int>& candidates, vector<vector<int>> & res, vector<int> &ds){
        if(index == candidates.size()){
            if(target == 0){
                res.push_back(ds);
            }
            return;
        }

        if(candidates[index] <= target){
            ds.push_back(candidates[index]);
            helper(index, target - candidates[index], candidates, res, ds);
            ds.pop_back();
        }
        helper(index + 1, target, candidates, res, ds);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        helper(0, target, candidates, res, ds);
        return res;
    }
};
