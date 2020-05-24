class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        
        for (char m : magazine)
            mp[m]++;
        
        for (char r : ransomNote) {
            if (mp.find(r) == mp.end() || mp[r] == 0)
                return false;
            mp[r]--;
        }
        return true;
    }
};
