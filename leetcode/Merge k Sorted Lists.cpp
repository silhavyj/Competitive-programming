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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        
        vector<int> nums;
        for (auto list : lists)
            while (list != NULL) {
                nums.push_back(list->val);
                list = list->next;
            }
        if (nums.size() == 0)
            return NULL;
        sort(nums.begin(), nums.end());
        
        ListNode *curr = new ListNode(nums[0]);
        ListNode *root = curr;
        
        for (int i = 1; i < nums.size(); i++) {
            curr->next = new ListNode(nums[i]);
            curr = curr->next;
        }
        return root;
    }
};
