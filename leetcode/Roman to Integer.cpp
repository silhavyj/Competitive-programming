class Solution {
private:
    vector<vector<string>> r = {
        {"I","II","III","IV","V","VI","VII","VIII","IX"},
        {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
        {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"}
    };
public:
    int romanToInt(string s) {
        int i = 0;
        int ans = 0;
        while (i < s.length()) {
            if (s[i]=='M') {
                ans += 1000;
                i++;
            } else {
                bool found = false;
                for (int j = r.size()-1; j >= 0 && !found; j--)
                    for (int k = r[j].size()-1; k >= 0 && !found; k--) {
                        if (s.substr(i,r[j][k].length()) == r[j][k]) {
                            found = true;
                            i += r[j][k].length();
                            int val = k+1;
                            for (int l=0; l<j; l++)
                                val *= 10;
                            ans += val;
                        }
                    }
            }
        }
        return ans;
    }
};
