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
    
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
            return NULL;
        
        ListNode *odd = NULL, *oddHead = NULL;
        ListNode *even = NULL, *evenHead = NULL;
        
        ListNode *curr = head;
        int index = 0;
        
        while (curr != NULL) {
            if (++index & 1) {
                if (odd == NULL)
                    odd = oddHead = new ListNode(curr->val);
                else {
                    odd->next = new ListNode(curr->val);
                    odd = odd->next;
                }
            }
            else {
                if (even == NULL)
                    even = evenHead = new ListNode(curr->val);
                else {
                    even->next = new ListNode(curr->val);
                    even = even->next;
                }
            }
            curr = curr->next;
        }
        odd->next = evenHead;
        return oddHead;
    }
};
