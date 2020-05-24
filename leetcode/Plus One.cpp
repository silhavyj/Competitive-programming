class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans = digits;
        int c = 0;
        int i = digits.size()-1;
        bool last = true;
        do {
            ans[i] += c;
            if (last) {
                last = false;
                ans[i]++;
            }
            if (ans[i] >= 10) {
                c = ans[i] / 10;
                ans[i] %= 10;
            }
            else c = 0;
            if (--i == -1)
                break;
        } while (c);
        if (c)
            ans.insert(ans.begin(),c);
        return ans;
    }
};
