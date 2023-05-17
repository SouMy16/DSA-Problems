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
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        while(head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        int ans = 0;
        for(int i=0; i<v.size()-1-i; i++)
        {
            ans = max(ans, v[i]+v[v.size()-1-i]);
        }
        return ans;
    }
};