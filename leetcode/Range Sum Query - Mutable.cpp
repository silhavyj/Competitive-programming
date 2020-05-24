class NumArray {
public:
    vector<int> nums;
    
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    void update(int i, int val) {
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; k++)
            sum += nums[k];
        return sum;
    }
};
