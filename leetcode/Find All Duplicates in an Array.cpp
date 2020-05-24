static int x=[](){ios_base::sync_with_stdio(false); cin.tie(NULL); return 0;}();
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> pairs;
        vector<int> ans;
        
        for (int n : nums) {
            pairs[n]++;
            if (pairs[n] == 2)
                ans.push_back(n);
        }        
        return ans;
    }
};
