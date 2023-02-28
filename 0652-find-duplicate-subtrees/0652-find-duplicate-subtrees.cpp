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
    string inOrder(TreeNode* root, map<string, vector<TreeNode*>> &m)
    {
        if(!root) return "";
        string ans = "(";
        ans += inOrder(root->left, m);
        string num = to_string(root->val);
        ans += num;
        ans += inOrder(root->right, m);
        ans += ")";
        m[ans].push_back(root);
        // cout<<ans<<'\n';
        return ans;
    }
    bool isSame(TreeNode* r1, TreeNode* r2)
    {
        if(!r1 && !r2) return true;
        if(!r1 || !r2 || r1->val!=r2->val) return false;
        return isSame(r1->left, r2->left) && isSame(r1->right, r2->right);
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        map<string, vector<TreeNode*>> m;
        inOrder(root, m);
        for(map<string, vector<TreeNode*>>::iterator it = m.begin(); it!=m.end(); it++)
        {
            // cout<<it->first<<'\n';
            if(it->second.size() > 1) ans.push_back(it->second[0]);
        }
        return ans;
    }
};