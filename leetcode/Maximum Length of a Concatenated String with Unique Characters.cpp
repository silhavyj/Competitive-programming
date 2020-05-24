class Solution {
public:
    
    int ans = 0;
    
    void solve(int p, vector<string>& arr, int *f) {
        if (p == arr.size())
            return;
        solve(p+1, arr, f);
        bool ok = true;
        for (int i = 0; i < arr[p].length() && ok; i++)
            ok &= f[arr[p][i]-'a'] == 0;
        unordered_set<char> unique;
        for (char c : arr[p]) {
            if (unique.find(c) != unique.end()) {
                ok = false;
                break;
            }
            unique.insert(c);
        }
        if (ok) {
            int count = 0;
            for (char c : arr[p])
                f[c-'a']++;
            for (int i = 0; i < 26; i++)
                count += f[i];
            ans = max(ans, count);
            solve(p,arr,f);
            for (char c : arr[p])
                f[c-'a']--;
        }
    }
    
    int maxLength(vector<string>& arr) {
        int f[26];
        for (int i = 0; i < 26; i++)
            f[i] = 0;
        solve(0, arr, f);
        return ans;
    }
};
