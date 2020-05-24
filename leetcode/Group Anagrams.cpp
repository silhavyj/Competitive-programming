class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> count;
        vector<vector<string>> res;
        
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            count[t].push_back(s);
        }
        for (auto p : count)
            res.push_back(p.second);
        return res;
    }
};
