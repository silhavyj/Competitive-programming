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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode *node = head;
        while (node != NULL) {
            n++;
            node = node->next;
        }
        vector<ListNode*> ans;
        int len = n/k;
        if (len==0) {
            node = head;
            while (node != NULL) {
                ans.push_back(new ListNode(node->val));
                node = node->next;
            }
            for (int i = 0; i < k-n; i++)
                ans.push_back(NULL);
        } else {
            /*
                n=10, k=3
                n/k=3, n%k=1
                n-n%k = 10-1=9
            */
            node = head;
            for (int j=0; j < n%k; j++) {
                ListNode *part = NULL;
                for (int i = 0; i < n/k+1; i++) {
                    if (part == NULL) {
                        part = new ListNode(node->val);
                        ans.push_back(part);
                    } else {
                        part->next = new ListNode(node->val);
                        part = part->next;
                    }
                    node = node->next;
                }
            }
            while (node != NULL) {
                ListNode *part = NULL;
                for (int i = 0; i < n/k; i++) {
                    if (part == NULL) {
                        part = new ListNode(node->val);
                        ans.push_back(part);
                    } else {
                        part->next = new ListNode(node->val);
                        part = part->next;
                    }
                    node = node->next;
                }
            }
        }
        return ans;
    }
};
