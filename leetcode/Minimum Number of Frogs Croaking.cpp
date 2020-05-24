class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char,int> mp;
        int frogs = 0;
        int ans = 0;
        
        for (char c : croakOfFrogs) {
            mp[c]++;
            if (c == 'c')
                frogs++;
            if (c == 'k')
                frogs--;
            ans = max(ans, frogs);
            if (mp['c'] < mp['r'] || mp['r'] < mp['o'] || mp['o'] < mp['a'] || mp['a'] < mp['k'])
                return -1;
        }
        if (mp['c'] == mp['r'] && mp['r'] == mp['o'] && mp['o'] == mp['a'] && mp['a'] == mp['k'])
            return ans;
        return -1;
    }
};
