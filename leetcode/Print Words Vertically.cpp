class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        int maxLen = 0;
        while (getline(ss, word, ' '))
            if (word!="") {
                words.push_back(word);
                maxLen = max(maxLen, (int)word.length());
            }
        vector<string> ans(maxLen);
        for (string w : words) {
            for (int i = 0; i < w.length(); i++)
                ans[i] += w[i];
            for (int i = w.length(); i < maxLen; i++)
                ans[i] += ' ';
        }
        for (int i = 0; i < maxLen; i++)
            while (ans[i].back()==' ')
                ans[i].pop_back();
        return ans;
    }
};
