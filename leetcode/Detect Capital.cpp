class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitals = 0;
        for (char c : word)
            capitals += (c >= 'A' && c <= 'Z');
        return capitals == 0 || (capitals == 1 && word[0] >= 'A' && word[0] <= 'Z') || capitals == word.length();  
    }
};
