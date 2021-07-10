class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int t = min(num1.length(), num2.length());
        int c=0;
        int i;
        for (i = 0; i < t; i++) {
            int x = c + (num1[i]-'0') + (num2[i]-'0');
            ans += to_string(x%10);
            c = x/10; 
        }
        while (i < num1.length()) {
            int x = c + (num1[i++]-'0');
            ans += to_string(x%10);
            c = x/10; 
        } 
        while (i < num2.length()) {
            int x = c + (num2[i++]-'0');
            ans += to_string(x%10);
            c = x/10; 
        }
        if (c != 0)
            ans += to_string(c);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
