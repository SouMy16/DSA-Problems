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
    TreeNode* findGCA(TreeNode* root, int startValue, int destValue) {
        if(!root) return NULL;
        if(root->val == startValue || root->val == destValue) return root;
        TreeNode* isRight = findGCA(root->right, startValue, destValue);
        TreeNode* isLeft = findGCA(root->left, startValue, destValue);
        if(isRight && isLeft) return root;
        else if(isRight) return isRight;
        return isLeft;
    }

    bool findNode(TreeNode* root, int value) {
        if(!root) return false;
        if(root->val == value) return true;
        return findNode(root->left, value) || findNode(root->right, value);
    }

    void path(TreeNode* root, int value, string &ans, string &res) {
        if(!root) return;
        if(root->val == value) {
            res = ans;
            return;
        }
        ans.push_back('L');
        path(root->left, value, ans, res);
        ans.pop_back();
        if(res != "") return;
        ans.push_back('R');
        path(root->right, value, ans, res);
        ans.pop_back();
        return;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* gca = findGCA(root, startValue, destValue);
        string ans = "";
        string leftstr = "";
        string rightstr = "";
        bool isLeft = findNode(gca->left, startValue);
        if(isLeft) {
            string s = "";
            path(gca, startValue, s, leftstr);
            path(gca, destValue, s, rightstr);
            for(int i=0; i<leftstr.size(); i++) leftstr[i] = 'U';
            ans = leftstr + rightstr;
        } else {
            string s = "";
            path(gca, startValue, s, rightstr);
            path(gca, destValue, s, leftstr);
            for(int i=0; i<rightstr.size(); i++) rightstr[i] = 'U';
            ans = rightstr + leftstr;
        }
        return ans;
    }
};