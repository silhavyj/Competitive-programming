class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int l,r;
        if (arr[0] >= x) {
            l = -1;
            r = l+1;
        } else if (arr[arr.size()-1] <= x) {
            r = arr.size();
            l = r-1;
        } else {
            for (int i = 0; i < arr.size()-1; i++) {
                if (arr[i] <= x && arr[i+1] >= x) {
                    l=i;
                    r=i+1;
                    break;
                }
            }   
        }
        while (ans.size() != k) {
            if (l >= 0 && r < arr.size()) {
                if (abs(arr[l]-x) <= abs(arr[r]-x)) {
                    ans.push_back(arr[l--]);
                } else {
                    ans.push_back(arr[r++]);
                }
            } else {
                if (l >= 0)
                    ans.push_back(arr[l--]);
                else
                     ans.push_back(arr[r++]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
