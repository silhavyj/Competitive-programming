class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;
        for (int i = 0; i < s.length(); i++)
            last[s[i]] = i;
        vector<int> pos, ans;
        for (auto p : last)
            pos.push_back(p.second);
        sort(pos.begin(), pos.end());
        int start = 0;
        for (int i = 0; i < pos.size(); i++) {
            bool works = true;
            for (int j = start; j < pos[i] && works; j++) {
                if (last[s[j]] > pos[i])
                    works = false;
            }
            if (works) {
                ans.push_back(pos[i]-start+1);
                start = pos[i]+1;
            }
        }
        return ans;
    }
};
