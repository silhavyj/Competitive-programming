class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewes;
        int ans = 0;
        
        for (char j : J)
            jewes.insert(j);
        
        for (char s : S)
            ans += jewes.find(s) != jewes.end();
        return ans;
    }
};
