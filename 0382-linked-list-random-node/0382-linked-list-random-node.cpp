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
    int n = 0;
    ListNode* actHead;
    Solution(ListNode* head) {
        ListNode* cur = head;
        actHead = head;
        while(cur)
        {
            cur = cur->next;
            n++;
        }
    }
    
    int getRandom() {
        int r = rand()%n;
        ListNode* cur = actHead;
        for(int i=0; i<r; i++) cur = cur->next;
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */