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
    int ans = INT_MIN;
    int maxPathSum1(TreeNode* root)
    {
        if(!root) return 0;
        int l = maxPathSum1(root->left);
        int r = maxPathSum1(root->right);
        // ans = ;
        ans = max(ans, l + r + root->val);
        return max(max(l, r) + root->val, 0);
    }
    int maxPathSum(TreeNode* root) {
        maxPathSum1(root);
        return ans;
    }
};