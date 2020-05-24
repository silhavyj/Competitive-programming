class Solution {
public:
    
    void rotate(list<char> &chars, bool left, int n) {
        for (int i = 0; i < n; i++) {
            if (left) {
                char f = chars.front();
                chars.pop_front();
                chars.push_back(f);
            }
            else {
                char l = chars.back();
                chars.pop_back();
                chars.push_front(l);
            }
        }
    } 
    
    string stringShift(string s, vector<vector<int>>& shift) {
        list<char> chars;
        
        for (char c : s)
            chars.push_back(c);
        
        for (auto sh : shift)
            rotate(chars, sh[0] == 0, sh[1]);
            
        string ans = "";
        for (char c : chars)
            ans += c;
        return ans;
    }
};
