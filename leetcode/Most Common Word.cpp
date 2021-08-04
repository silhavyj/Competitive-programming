class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> forbitten;
        for (string w : banned)
            forbitten.insert(w);
        int p = 0;
        string ans = "";
        unordered_map<string,int> counter;
        int i = 0;
        for (; i < paragraph.length(); i++) {
            if (paragraph[i] >= 'A' && paragraph[i] <= 'Z')
                paragraph[i] += 32;
            else if (paragraph[i] < 'a' || paragraph[i] > 'z') {
                string word = paragraph.substr(p, i-p);
                p = i+1;
                if (word == "")
                    continue;
                counter[word]++;
                if (!forbitten.count(word)) {
                    if (ans == "")
                        ans = word;
                    else if (counter[word] > counter[ans])
                        ans = word;
                }
            }
        }
        if (i != p) {
            string word = paragraph.substr(p, i-p);
            p = i+1;
            counter[word]++;
            if (!forbitten.count(word)) {
                if (ans == "")
                    ans = word;
                else if (counter[word] > counter[ans])
                    ans = word;
            }
        }
        return ans;
    }
};
