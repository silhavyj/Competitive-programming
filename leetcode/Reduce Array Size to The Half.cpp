class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for (int a : arr)
            mp[a]++;
        vector<int> amounts;
        for (auto p : mp)
            amounts.push_back(p.second);
        sort(amounts.begin(), amounts.end());
        int n = arr.size();
        int d=0, ans=0, i=amounts.size()-1;
        while (d < n/2) {
            d += amounts[i--];
            ans++;
        }
        return ans;
    }
};
