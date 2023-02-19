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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int rtl = 0;
        while(!q.empty())
        {
            vector<int> v;
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(!cur) continue;
                v.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(rtl) reverse(v.begin(), v.end());
            ans.push_back(v);
            rtl ^= 1;
        }
        return ans;
    }
};