lass Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        unordered_set<int> s1,  s2;
        for (char c : str1)
            s1.insert(c);
        for (char c : str2)
            s2.insert(c);
        if (s1.size() != s2.size())
            return "";
        string d = str1.length() < str2.length() ? str1 : str2;
        int len = d.length();
        while (len > 0) {
            int p1 = 0;
            int p2 = 0;
            string ans = str1.substr(0,len);
            //cout << ans << "\n";
            bool ok = true;
            int i;
            for (i = 0; i < str1.length() && ok; i++)
                if (str1[i] != ans[i%len])
                    ok = false;
            if (i % len != 0)
                ok = false;
            for (i = 0; i < str2.length() && ok; i++)
                if (str2[i] != ans[i%len])
                    ok = false;
            if (ok && i % len == 0)
                return ans;
            len--;
        }
        return "";
    }
};
