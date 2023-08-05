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

    vector<TreeNode*> generateTrees(int st, int en) {
        vector<TreeNode*> ans;
        if(st>en){
            ans.push_back(NULL);
            return ans;
        }
        if(st==en){
            ans.push_back(new TreeNode(st));
            return ans;
        }
        for(int i=st; i<=en; i++)
        {
            vector<TreeNode*> left = generateTrees(st, i-1);
            vector<TreeNode*> right = generateTrees(i+1, en);
            for(int j=0; j<left.size(); j++)
            {
                for(int k=0; k<right.size(); k++)
                {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = left[j];
                    cur->right = right[k];
                    ans.push_back(cur);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        for(int i=1; i<=n; i++)
        {
            vector<TreeNode*> left = generateTrees(1, i-1);
            vector<TreeNode*> right = generateTrees(i+1, n);
            for(int j=0; j<left.size(); j++)
            {
                for(int k=0; k<right.size(); k++)
                {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = left[j];
                    cur->right = right[k];
                    ans.push_back(cur);
                }
            }
            // if(left.size() == 0)
            // {
            //     for(int k=0; k<right.size(); k++)
            //     {
            //         TreeNode* cur = new TreeNode(i);
            //         cur->left = NULL;
            //         cur->right = right[k];
            //         ans.push_back(cur);
            //     }
            // }
            // if(right.size() == 0)
            // {
            //     for(int k=0; k<left.size(); k++)
            //     {
            //         TreeNode* cur = new TreeNode(i);
            //         cur->left = left[k];
            //         cur->right = NULL;
            //         ans.push_back(cur);
            //     }
            // }
        }
        return ans;
    }
};