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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        
        int n = 0;
        ListNode *curr = head;
        while (curr != NULL)
            curr = curr->next, n++;
        
        if (n / k == 0)
            return head;
        
        int t = n % k;
        
        ListNode *ans = NULL;
        ListNode *ans_curr;
        
        curr = head;
        
        for (int i = 0; i < n-t; i++) {
            ListNode *chain = new ListNode(curr->val);
            ListNode *chain_head = chain;
            
            curr = curr->next;
            for (int j = 0; j < k-1; j++, i++) {
                ListNode *tmp = new ListNode(curr->val);
                tmp->next = chain;
                chain = tmp;
                curr = curr->next;
            }
            if (ans == NULL) 
                ans = chain;
            else ans_curr->next = chain;
            ans_curr = chain_head;
        }
        while (curr != NULL) {
            ans_curr->next = new ListNode(curr->val);
            ans_curr = ans_curr->next;
            curr = curr->next;
        }
        return ans;
    }
};
