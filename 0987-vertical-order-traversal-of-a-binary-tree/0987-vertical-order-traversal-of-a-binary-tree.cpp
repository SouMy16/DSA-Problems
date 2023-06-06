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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int, map<int, vector<int>>> m;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty())
        {
            TreeNode * cur = q.front().first;
            int x = q.front().second.second;
            int y = q.front().second. first;
            q.pop();
            if(cur->left) q.push({cur->left, {y-1, x+1}});
            if(cur->right) q.push({cur->right, {y+1, x+1}});
            m[y][x].push_back(cur->val);
        }
        int v = 0;
        ans.resize(m.size());
        for(auto y:m)
        {
            for(auto x:y.second)
            {
                sort(x.second.begin(), x.second.end());
                for(int i=0; i<x.second.size(); i++)
                {
                    ans[v].push_back(x.second[i]);
                }
            }
            v++;
        }
        return ans;
    }
};