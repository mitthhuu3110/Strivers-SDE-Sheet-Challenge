class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(st.empty())
                st.push(s[i]);
            
            else if(st.top() == '(' && s[i] ==')')
                st.pop();
            
            else if(st.top() == '{' && s[i] =='}')
                st.pop();
            
            else if(st.top() == '[' && s[i] ==']')
                st.pop();
                
            else
                st.push(s[i]);
        }
        return st.empty();
    }
};
