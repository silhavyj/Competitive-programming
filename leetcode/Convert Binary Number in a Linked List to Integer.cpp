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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        int p = 0;
        
        ListNode *curr = head;
        while (curr != NULL) {
            curr = curr->next;
            p++;
        }
        p = 1<<(p-1);
        while (head != NULL) {
            if (head->val==1)
                ans |= p;
            p >>= 1;
            head = head->next;
        }
        return ans;
    }
};
