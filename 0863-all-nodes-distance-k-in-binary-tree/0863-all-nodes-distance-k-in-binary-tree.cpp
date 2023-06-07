/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*> m;
    void distanceK(TreeNode* root, TreeNode* target, int k, vector<int> &ans, int cur)
    {
        if(root && cur == k)
        {
            ans.push_back(root->val);
            return;
        }
        if(!root || cur>k) return;
        if(root == target)
        {
            distanceK(root, NULL, k, ans, 0);
            // if(root->left)
            // {
            //     m[root->left] = root;
            //     distanceK(root->left, target, k, ans, 0);
            // }
            // if(root->right)
            // {
            //     m[root->right] = root;
            //     distanceK(root->right, target, k, ans, 0);
            // }
        }
        if(cur == -1)
        {
            if(root->left)
            {
                m[root->left] = root;
                distanceK(root->left, target, k, ans, -1);
            }
            if(root->right)
            {
                m[root->right] = root;
                distanceK(root->right, target, k, ans, -1);
            }
        }
        else{
            if(root->left)
            {
                m[root->left] = root;
                distanceK(root->left, target, k, ans, cur+1);
            }
            if(root->right)
            {
                m[root->right] = root;
                distanceK(root->right, target, k, ans, cur+1);
            }
        }
        return;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root) return ans;
        m[root] = NULL;
        distanceK(root, target, k, ans, -1);
        // if(root->left)
        // {
        //     m[root->left] = root;
        //     distanceK(root->left, target, k, ans, 0);
        // }
        // if(root->right)
        // {
        //     m[root->right] = root;
        //     distanceK(root->right, target, k, ans, 0);
        // }
        map<TreeNode*, int> vis;
        vis[target] = 1;
        TreeNode* cur = target;
        while(m[cur] != NULL && k>0)
        {
            cur = m[cur];
            vis[cur] = 1;
            k--;
            if(k == 0)
            {
                ans.push_back(cur->val);
                break;
            }
            if(!vis[cur->left]) distanceK(cur->left, NULL, k, ans, 1);
            if(!vis[cur->right]) distanceK(cur->right, NULL, k, ans, 1);
        }
        return ans;
    }
};