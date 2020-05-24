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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return head;
        
        ListNode *curr;
        ListNode *prev;
        ListNode *ans;
        
        curr = head;
        while (curr->val == val) {
            curr = curr->next;
            if (curr == NULL)
                return NULL;
        }
        
        ans = prev = curr;
        curr = curr->next;
        while (curr != NULL) {
            if (curr->val == val) 
                prev->next = curr->next;
            else prev = curr;
            curr = curr->next;
        }
        return ans;
    }
};
