class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        recursive(root, res);
        return res;
    }
    int recursive(TreeNode* root, int& res) {
        if (root == nullptr) {
            return 0;
        }
        int l = recursive(root->left, res);
        int r = recursive(root->right, res);
        res = max(res, l + r);
        return 1 + max(l, r);
    }
};
