class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for (int x : arr)
            mp[x]++;
        vector<int> v;
        for (auto p : mp)
            v.push_back(p.second);
        sort(v.begin(),v.end());
        int removed = 0;
        //for (int x : v) cout << x << " ";
        cout << endl;
        for (int x : v) {
            if (x <= k) {
                k -= x;
                removed++;
            }
            else break;
        }
        return v.size() - removed;
    }
};
