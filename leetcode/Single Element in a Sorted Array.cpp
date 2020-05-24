class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
	    if (nums.size() == 1)
		    return nums[0];
	
	    for (int i=0, j=1; i < (int)nums.size()-1; i+=2) {
		    if (nums[i] != nums[j])
			    return nums[i];
		    j+=2;
	    }
	    return nums[nums.size()-1];
    }
};
