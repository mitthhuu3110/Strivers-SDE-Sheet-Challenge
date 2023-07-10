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
    void helper(TreeNode* root,int height,int &mini){
        if(root==NULL){
            return;
        }
        if(root->right == NULL && root->left == NULL){
            mini=min(mini,height);
        }
        helper(root->left,height+1,mini);
        helper(root->right,height+1,mini);
    }
public:
    int minDepth(TreeNode* root) {
        int res = INT_MAX;
        if(root == NULL) return NULL;
        helper(root, 1 , res);
        return res;
    }
};
