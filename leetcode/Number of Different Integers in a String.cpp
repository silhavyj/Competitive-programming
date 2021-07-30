class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        int i = 0;
        while (i < word.length()) {
            if (isalpha(word[i])) {
                i++;
                continue;
            }
            string num = "";
            while (isdigit(word[i])) {
                num += word[i];
                i++;
            }
            while (*(num.begin())=='0')
                num.erase(num.begin());
            s.insert(num);
        }
        return s.size();
    }
};
