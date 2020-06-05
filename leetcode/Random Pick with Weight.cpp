class Solution {

vector<int> sum;
    
public:
    Solution(vector<int>& w) {
        for (int x : w) {
            if (sum.empty())
                sum.push_back(x);
            else sum.push_back(x + sum.back());
        }
    }
    
    int pickIndex() {
        int x = rand() % sum.back();
        int l=0, r=sum.size();
        while (l < r) {
            int m = l+(r-l)/2;
            if (x >= sum[m])
                l = m+1;
            else r=m;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
