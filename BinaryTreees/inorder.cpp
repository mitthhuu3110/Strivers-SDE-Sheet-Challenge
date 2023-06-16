/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
        stack<TreeNode*> st;
        
        while(true){
            if(root!=NULL){
                st.push(root);
                root=root->left;
            }else{
                if(st.empty()){
                    break;
                }
                TreeNode* top=st.top();
                ans.push_back(top->val);
                st.pop();
                
                if(top->right!=NULL){
                    root=top->right->left;
                    st.push(top->right);
                }
            } 
        }   
        return ans;
    }
};
