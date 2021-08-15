class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for (char c : t)
            mp[c]++;
        int distinct = mp.size();
        unordered_map<char,int> window;
        int count = 0;
        int ll=0, rr=0, l=0, r=0;
        int ans = INT_MAX;
        
        while (r < s.length()) {
            window[s[r]]++;
            if (mp.count(s[r]) && mp[s[r]]==window[s[r]])
                count++;
            r++;
            while (count == distinct && l<r) {
                if (ans > r-l) {
                    ans = r-l;
                    ll = l;
                    rr = r;
                }
                window[s[l]]--;
                if (mp.count(s[l]) && window[s[l]] < mp[s[l]])
                    count--;
                l++;
            }
        }
        return s.substr(ll,rr-ll);
    }
};
