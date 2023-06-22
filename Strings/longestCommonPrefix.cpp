class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
        string res = "";
        sort(strs.begin(), strs. end());
        string s = strs[0];
        string e = strs[n-1];
        for(int i = 0; i < s.size(); i++){
            if(s[i] == e[i]){
                res = res + s[i];
            }else break;
        }
        return res;
    }
};
