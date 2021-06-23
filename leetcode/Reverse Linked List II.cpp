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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *curr = head;
        ListNode *start = head;
        for (int i = 0; i < left-1; i++) {
            start = curr;
            curr = curr->next;
        }
        ListNode *first = curr;
        ListNode *last = curr;
        for (int i = left; i < right; i++) {
            curr = last->next;
            if (curr == NULL)
                break;
            last->next = last->next->next;
            curr->next = first;
            first = curr;
        }
        if (left == 1)
            return first;
        start->next = first;
        return head;
    }
};
