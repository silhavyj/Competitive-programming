class Solution {
public:
    string sortSentence(string s) {
        int spaces = 0;
        for (char c : s)
            spaces += c == ' ';
        vector<string> sentence(spaces+1);
        int p=0,i, j, index;
        int n = s.length();
        for (i = 0; i < n; i++) {
            if (s[i]==' ') {
                j = i-1;
                while (j >= 0 && s[j]>='0' && s[j]<='9')
                    j--;
                index = atoi(s.substr(j+1, i-j).c_str());
                sentence[index-1] = s.substr(p,j-p+1);
                p=i+1;
            }
        }
        j = i-1;
        while (j >= 0 && s[j]>='0' && s[j]<='9')
            j--;
        index = atoi(s.substr(j+1, i-j).c_str());
        sentence[index-1] = s.substr(p,j-p+1);
        string ans = "";
        for (string w : sentence)
            ans += w + " ";
        ans.pop_back();
        return ans;
    }
};
