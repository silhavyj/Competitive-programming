class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        
        int mp1[26], mp2[26];
        bool same;
        
        for (int i = 0; i < 26; i++)
            mp1[i] = mp2[i] = 0;
        
        for (char c : s1)
            mp1[c-'a']++;
        
        for (int i = 0; i < s1.length(); i++)
            mp2[s2[i]-'a']++;
        
        for (int k=0; ;k++) {
            same = true;
            for (int i = 0; i < 26 && same; i++)
                same &= mp1[i] == mp2[i];
            if (same)
                return true;
            if (s1.length()+k >= s2.length())
                break;
            mp2[s2[k]-'a']--;
            mp2[s2[s1.length()+k]-'a']++;
        }
        return false;
    }
};
