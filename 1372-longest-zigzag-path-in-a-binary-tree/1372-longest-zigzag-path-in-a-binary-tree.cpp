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
    map<TreeNode*, int> rig, lef;
    int ans = 0;
public:
    void findLen(TreeNode* root)
    {
        if(!root) return;
        if(root->left)
        {
            findLen(root->left);
            lef[root] = 1+rig[root->left];
        }
        else{
            lef[root] = 0;
        }
        
        if(root->right)
        {
            findLen(root->right);
            rig[root] = 1+lef[root->right];
        }
        else{
            rig[root] = 0;
        }
        
        ans = max(ans, max(rig[root], lef[root]));
        return;
    }
    int longestZigZag(TreeNode* root) {
        findLen(root);
        return ans;
    }
};