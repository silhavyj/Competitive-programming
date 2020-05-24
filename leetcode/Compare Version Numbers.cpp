class Solution {
public:
    
    vector<int> tokenize(string version) {
        vector<int> res;
        stringstream ss(version);
        string token;
        while (getline(ss,token,'.'))
            res.push_back(atoi(token.c_str()));
        return res;
    }
    
    int compareVersion(string version1, string version2) {
        auto t1 = tokenize(version1);
        auto t2 = tokenize(version2);
        int n = max(t1.size(), t2.size());
        for (int i = 0; i < n; i++) {
            int p1 = i < t1.size() ? t1[i] : 0;
            int p2 = i < t2.size() ? t2[i] : 0;
            if (p1 < p2)
                return -1;
            else if (p1 > p2)
                return 1;
        }
        return 0;
    }
};
