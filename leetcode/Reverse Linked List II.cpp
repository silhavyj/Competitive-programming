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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL)
            return NULL;
        
        int i = 1;
        ListNode *curr = head;
        vector<int> nums;
        stack<int> st;
        
        while (curr != NULL) {
            if (i >= m && i <= n) {
                st.push(curr->val);
                if (i == n) {
                    while (!st.empty()) {
                        nums.push_back(st.top());
                        st.pop();
                    }
                }
            }
            else nums.push_back(curr->val);
            curr = curr->next;
            i++;
        }
        
        ListNode *res = new ListNode(nums[0]);
        curr = res;
        for (int i = 1; i < nums.size(); i++) {
            curr->next = new ListNode(nums[i]);
            curr = curr->next;
        }
        return res;
    }
};
