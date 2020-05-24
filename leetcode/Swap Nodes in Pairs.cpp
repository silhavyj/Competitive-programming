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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode *ans = NULL;
        ListNode *curr;
        while (head != NULL) {
            ListNode *x = head;
            ListNode *y = head->next;
            if (y == NULL) {
                if (ans == NULL)
                    ans = new ListNode(x->val);
                else curr->next = new ListNode(x->val);
                break;
            }
            if (ans == NULL) {
                ans = new ListNode(y->val);
                ans->next = new ListNode(x->val);
                curr = ans->next;
            }
            else {
                curr->next = new ListNode(y->val);
                curr = curr->next;
                curr->next = new ListNode(x->val);
                curr = curr->next;
            }
            head = head->next->next;
        }
        return ans;
    }
};
