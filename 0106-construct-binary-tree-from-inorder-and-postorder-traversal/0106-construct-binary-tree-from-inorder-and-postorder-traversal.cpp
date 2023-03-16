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
    TreeNode* build(vector<int> &inorder, vector<int> &postorder, int &p, int instart, int inend, unordered_map<int,int> &m)
    {
        if(instart>inend || p<0) return NULL;
        int ele = postorder[p];
        p--;
        int pos = m[ele];
        TreeNode* root = new TreeNode(ele);
        // if(p<0) return root;
        root->right = build(inorder, postorder, p, pos+1, inend,m);
        root->left = build(inorder, postorder, p, instart, pos-1,m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i=0;i<postorder.size();i++) m[inorder[i]] = i;
        int p=postorder.size()-1;
        TreeNode* head = build(inorder,postorder,p,0,inorder.size()-1,m);
        return head;
    }
};