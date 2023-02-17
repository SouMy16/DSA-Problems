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
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            v.push_back(cur->val);
        }
        for(int i=0; i<v.size(); i++)
        {
            for(int j = i+1; j<v.size(); j++)
            {
                ans = min(ans, abs(v[i]-v[j]));
            }
        }
        return ans;
    }
};