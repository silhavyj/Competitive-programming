class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> a,b;
        for (int x : A) {
            if (x & 1)
                b.push_back(x);
            else a.push_back(x);
        }
        vector<int> ans(A.size());
        for (int i = 0; i < a.size(); i++)
            ans[i] = a[i];
        for (int i = 0; i < b.size(); i++)
            ans[a.size()+i] = b[i];
        return ans;
    }
};
