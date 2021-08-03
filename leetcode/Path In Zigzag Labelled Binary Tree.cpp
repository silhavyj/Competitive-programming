class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int depth = log2(label) + 1;
        int sum = pow(2,depth-1) + pow(2,depth)-1;
        while (label > 0) {
            ans.push_back(label);
            int alt = sum - label;
            label = alt / 2;
            sum = (sum - 1) / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
