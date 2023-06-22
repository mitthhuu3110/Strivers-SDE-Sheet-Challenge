class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        for(int i = 0; i < n+m; i++){
            res.push_back(nums1[i]);
            res.push_back(nums2[i]);
        }
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++){
            nums1[i] = res[i];
        }
    }
};
