class Solution {
    vector<int> original;
    vector<int> arr;
    
public:
    Solution(vector<int>& nums) {
        original = nums;
        arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        arr = original;
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < arr.size(); i++) {
            int p = i + (rand() % (arr.size() - i));
            swap(arr[i], arr[p]);
        }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
