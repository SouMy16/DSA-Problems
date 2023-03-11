/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL)
        {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        TreeNode* root = new TreeNode();
        int n = 0;
        ListNode* cur = head;
        while(cur)
        {
            cur = cur->next;
            n++;
        }
        n = n/2;
        cur = head;
        n--;
        while(n--) cur = cur->next;
        root->val = cur->next->val;
        ListNode* r = cur->next->next;
        cur->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(r);
        return root;
    }
};