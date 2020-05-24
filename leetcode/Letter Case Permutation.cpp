class Solution {
public:
    
    vector<string> ans;
    
    void solve(string text, string curr, int i) {
        if (i == text.size()) {
            ans.push_back(curr);
            return;
        }
        if (text[i] >= 'A' && text[i] <= 'Z') {
            solve(text, curr + (char)(text[i]+32), i+1);
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            solve(text, curr + (char)(text[i]-32), i+1);
        }
        solve(text, curr+text[i], i+1);
    }
    
    vector<string> letterCasePermutation(string S) {
        solve(S, "", 0);
        return ans;
    }
};
