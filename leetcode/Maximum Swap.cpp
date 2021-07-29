class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for (int i = 0; i < s.length(); i++) {
            int k = i;
            for (int j = i+1; j < s.length(); j++)
                if (s[j] >= s[k])
                    k = j;
            if (k == i ||  s[k]==s[i])
                continue;
            swap(s[i], s[k]);
            return atoi(s.c_str());
        }
        return num;
    }
};
