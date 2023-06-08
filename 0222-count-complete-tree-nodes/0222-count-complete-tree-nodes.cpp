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
    int countNodes(TreeNode* root) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        int level = -1;
        int ans = 0;
        while(!q.empty())
        {
            level++;
            int n = q.size();
            ans += n;
            if(n!=pow(2, level)) return ans;
            for(int i=0; i<n; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->right) q.push(cur->right);
                if(cur->left) q.push(cur->left);
            }
            
        }
        return ans;
    }
};