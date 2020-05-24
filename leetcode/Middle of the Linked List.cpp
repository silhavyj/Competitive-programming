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
    ListNode* middleNode(ListNode* head) {
        ListNode *curr = head;
        int n = 0, p;
        while (curr != NULL) {
            curr = curr->next;
            n++;
        }
        p = n/2;
        curr = head;
        for (int i = 0; i < p; i++)
            curr = curr->next;
        return curr;
    };
};
