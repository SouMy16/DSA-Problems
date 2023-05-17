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
        int ans = 0;
        stack<int> st;
        ListNode* slow=head, *fast=head;
        while(fast)
        {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        while(slow)
        {
            ans = max(ans, st.top()+slow->val);
            st.pop();
            slow = slow->next;
        }
        return ans;
    }
};