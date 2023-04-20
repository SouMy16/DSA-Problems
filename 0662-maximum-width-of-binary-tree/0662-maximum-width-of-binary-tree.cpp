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
    int widthOfBinaryTree(TreeNode* root) {
        map<unsigned long long int, unsigned long long int> lef, rig;
        queue<pair<TreeNode*,unsigned long long int>> q;
        if(root) q.push({root,0});
        int level = 0;
        unsigned long long int ans = 0;
        while(!q.empty())
        {
            int n = q.size();
            unsigned long long int mx = q.front().second;
            unsigned long long int mn = q.front().second;
            for(int i=0; i<n; i++)
            {
                TreeNode* cur = q.front().first;
                unsigned long long int off = q.front().second;
                q.pop();
                if(cur->left) q.push({cur->left, 2*off});
                if(cur->right) q.push({cur->right, 2*off+1});
                mn = min(mn, off);
                mx = max(mx, off);
            }
            ans = max(ans, mx-mn+1);
            level++;
        }
        return ans;
    }
};