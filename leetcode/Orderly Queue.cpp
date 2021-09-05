class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans = s;
        if (k == 1) {
            for (int i = 0; i < s.length(); i++) {
                string tmp = s.substr(i) + s.substr(0,i);
                if (tmp < ans)
                    ans = tmp;
            }
        } else {
            sort(ans.begin(), ans.end());
        }
        return ans;
    }
};
