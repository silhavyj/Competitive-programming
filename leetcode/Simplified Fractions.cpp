class Solution {
    int gdc(int a, int b) {
        if (b==0)
            return a;
        return gdc(b, a % b);
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; i++)
            for (int j = i+1; j <= n; j++) {
                if (gdc(i,j) == 1)
                    ans.push_back(to_string(i) + "/" + to_string(j));
            }
        return ans;
    }
};
