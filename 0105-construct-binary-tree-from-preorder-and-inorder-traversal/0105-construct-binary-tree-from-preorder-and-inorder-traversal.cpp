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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n==0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int> prelef, inlef, inrig, prerig;
        for(int i=0; i<n; i++)
        {
            if(preorder[0] == inorder[i]) break;
            inlef.push_back(inorder[i]);
            prelef.push_back(preorder[i+1]);
        }
        for(int i=inlef.size()+1; i<n; i++)
        {
            inrig.push_back(inorder[i]);
            prerig.push_back(preorder[i]);
        }
        root->left = buildTree(prelef, inlef);
        root->right = buildTree(prerig, inrig);
        return root;
    }
};