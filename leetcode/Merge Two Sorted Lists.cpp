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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* curr = NULL;
        
        if (l1 == NULL && l2 == NULL)
            return curr;
        
        if (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                curr = new ListNode(l1->val);
                l1 = l1->next;
            }
            else {
                curr = new ListNode(l2->val);
                l2 = l2->next;
            }
        }
        else if (l1 == NULL) {
            curr = new ListNode(l2->val);
            l2 = l2->next;
        }
        else {
             curr = new ListNode(l1->val);
             l1 = l1->next;
        }
        ListNode* root = curr;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                curr->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else {
                curr->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            curr = curr->next;
        }
        while (l1 != NULL) {
            curr->next = new ListNode(l1->val);
            l1 = l1->next;
            curr = curr->next;
        }
        while (l2 != NULL) {
            curr->next = new ListNode(l2->val);
            l2 = l2->next;
            curr = curr->next;
        }
        return root;
    }
};
