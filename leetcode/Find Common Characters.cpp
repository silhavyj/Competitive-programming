class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<unordered_map<char,int>> mp;
        unordered_set<char> common;
        
        for (string word : words) {
            unordered_map<char,int> wmp;
            for (char c : word) {
                common.insert(c);
                wmp[c]++;
            }
            cout << word << '\n';
            for (auto p : wmp)
                cout << p.first << " " << p.second << '\n';
            mp.push_back(wmp);
        }
        cout << '\n';
        vector<string> ans;
        for (char c : common) {
            int minCount = INT_MAX;
            for (auto w : mp) {
                if (!w.count(c)) {
                    minCount=0;
                    break;
                }
                minCount = min(minCount, w[c]);
            }
            cout << c << " " << minCount << "\n";
            string s(1,c);
            for (int i = 0; i < minCount; i++)
                ans.push_back(s);
        }
        return ans;
    }
};
