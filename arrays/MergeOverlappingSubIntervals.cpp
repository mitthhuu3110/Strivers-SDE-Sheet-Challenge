class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(!res.empty() && end <= res.back()[1]){
                continue;
            }
            for(int j = i+1; j < n; j++){
                if(intervals[j][0] <= end){
                    end = max(end, intervals[j][1]);
                }else break;
            }
            res.push_back({start, end});
        }
        return res;
    }
};
