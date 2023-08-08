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
    void helper(TreeNode* root, vector<string> &res, string currPath){
        if(root == NULL) return;
        if(root -> right == NULL && root -> left == NULL){
            currPath += to_string(root -> val);
            res.push_back(currPath);
            return;
        }

        currPath += to_string(root -> val) + "->";
        if(root -> left) helper(root -> left, res, currPath);
        if(root -> right) helper(root -> right, res, currPath);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        helper(root, res, "");
        return res;
    }
};
