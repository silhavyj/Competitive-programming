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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string n1="", n2="";
        ListNode *curr = l1;
        while (curr != NULL) {
            n1 = to_string(curr->val) + n1;
            curr = curr->next;
        }
        curr = l2;
        while (curr != NULL) {
            n2 = to_string(curr->val) + n2;
            curr = curr->next;
        }
        ListNode *ans = NULL;
        int m=min(n1.length(),n2.length());
        int c = 0;
        int i = 0;
        for (; i < m; i++) {
            int x = c + (n1[i]-'0') + (n2[i]-'0');
            c = x / 10;
            ListNode *node = new ListNode(x%10);
            if (ans == NULL)
                ans = node;
            else {
                node->next = ans;
                ans = node;
            }
        }
        while (i < n1.length()) {
            int x = c + (n1[i++]-'0');
            c = x / 10;
            ListNode *node = new ListNode(x%10);
            if (ans == NULL)
                ans = node;
            else {
                node->next = ans;
                ans = node;
            }
        }
        while (i < n2.length()) {
            int x = c + (n2[i++]-'0');
            c = x / 10;
            ListNode *node = new ListNode(x%10);
            if (ans == NULL)
                ans = node;
            else {
                node->next = ans;
                ans = node;
            }
        }
        if (c != 0) {
            ListNode *node = new ListNode(c);
            if (ans == NULL)
                ans = node;
            else {
                node->next = ans;
                ans = node;
            }
        }
        return ans;
    }
};
