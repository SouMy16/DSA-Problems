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
    ListNode* mergeLists(ListNode* l1, ListNode* l2)
    {
        ListNode* ans = new ListNode(0);
        ListNode* head = ans;
        while(l1 && l2)
        {
            if(l1->val <= l2->val) 
            {
                ans->next = l1;
                l1 = l1->next;
            }
            else{
                ans->next = l2;
                l2 = l2->next;
            }
            ans = ans->next;
        }
        if(l1) ans->next = l1;
        if(l2) ans->next = l2;
        return head->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode* ans = lists[0];
        for(int i=1; i<lists.size(); i++) ans = mergeLists(ans, lists[i]);
        return ans;
    }
};