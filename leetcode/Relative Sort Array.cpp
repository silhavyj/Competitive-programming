class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> count;
        unordered_set<int> vals;
        vector<int> ans;
        
        for (int n : arr1) {
            count[n]++;
            vals.insert(n);
        }
        for (int n : arr2) {
            for (int i = 0; i < count[n]; i++)
                ans.push_back(n);
            vals.erase(n);
        }
        sort(arr1.begin(), arr1.end());
        for (int n : arr1)
            if (vals.find(n) != vals.end())
                ans.push_back(n);
        return ans;
    }
};
