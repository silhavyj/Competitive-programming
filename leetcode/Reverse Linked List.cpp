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
    ListNode* reverseList(ListNode* head) {
        ListNode *first = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = first;
            first = curr;
            curr = next;
        }
        return first;
    }
};
