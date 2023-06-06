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
        long long int ans = 0;
        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 1});
        while(!q.empty())
        {
            long long int n = q.size();
            long long int mn = q.front().second;
            long long int mx = INT_MIN;
            for(int i=0; i<n; i++)
            {
                long long int x = q.front().second;
                mx = max(mx, x);
                TreeNode* cur = q.front().first;
                q.pop();
                int l1 = x-mn+x;
                int l2 = x+1-mn+x;
                if(cur->left) q.push({cur->left, l1});
                if(cur->right) q.push({cur->right, l2});
            }
            ans = max(ans, mx-mn+1);
        }
        return ans;
    }
};