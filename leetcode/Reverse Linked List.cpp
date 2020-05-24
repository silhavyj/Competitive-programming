/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        
        ListNode *ans = new ListNode(head->val);
        ListNode *curr = head->next;
        
        while (curr != NULL) {
            ListNode *node = new ListNode(curr->val);
            node->next = ans;
            ans = node;
            curr = curr->next;
        }
        return ans;
    }
};
