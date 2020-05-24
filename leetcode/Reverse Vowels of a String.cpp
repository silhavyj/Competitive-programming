class Solution {
public:
    
    unordered_set<char> vowels = {'a','e','i','o','u'};

    string reverseVowels(string s) {
        vector<int> pos;
        
        for (int i = 0; i < s.length(); i++)
            if (vowels.find(tolower(s[i])) != vowels.end())
                pos.push_back(i);
        
        int n = pos.size();
        for (int i = 0; i < n/2; i++) {
            int p1 = pos[i];
            int p2 = pos[n-1-i];
            s[p1] = s[p1] ^ s[p2];
            s[p2] = s[p1] ^ s[p2];
            s[p1] = s[p1] ^ s[p2];
        }
        return s;
    }
};
