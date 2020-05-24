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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;
        
        int length = 0;
        ListNode *curr = head;
        
        while (curr != NULL) {
            length++;
            curr = curr->next;
        }        
        int pos = length - n;
        if (pos == 0)
            return head->next;
        
        curr = head;
        ListNode *prev = head;
        
        for (int i = 0; i < pos; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        return head;
    }
};
