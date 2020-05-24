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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr, *res;
        int sum, c = 0;
        
        if (l1 == NULL && l2 == NULL)
            return NULL;
        
        if (l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + c;
            curr = new ListNode(sum % 10);
            c = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1 != NULL) {
            sum = l1->val + c;
            curr = new ListNode(sum % 10);
            c = sum / 10;
            l1 = l1->next;
        }
        else {
            sum = l2->val + c;
            curr = new ListNode(sum % 10);
            c = sum / 10;
            l2 = l2->next;
        }
        res = curr;  
        while (l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + c;
            curr->next = new ListNode(sum % 10);
            c = sum / 10;
            
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            sum = l1->val + c;
            curr->next = new ListNode(sum % 10);
            c = sum / 10;
            curr = curr->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            sum = l2->val + c;
            curr->next = new ListNode(sum % 10);
            c = sum / 10;
            curr = curr->next;
            l2 = l2->next;
        }
        if (c != 0)
            curr->next = new ListNode(c);
        return res;
    }
};
