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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visited;
        
        ListNode *curr = headA;
        while (curr != NULL) {
            visited.insert(curr);
            curr = curr->next;
        }
        
        curr = headB;
        while (curr != NULL) {
            if (visited.find(curr) != visited.end())
                return curr;
            curr = curr->next;
        }
        return NULL;
    }
};
