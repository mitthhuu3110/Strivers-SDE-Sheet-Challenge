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
    int helper(TreeNode* root, bool leaf){
        if(root == NULL) return 0;
        int sum = 0;
        if(root -> left == NULL && root -> right == NULL && leaf){
            return root -> val;
        }

        int ls = helper(root -> left, true);
        int rs = helper(root -> right, false);
        return (ls+rs);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};
