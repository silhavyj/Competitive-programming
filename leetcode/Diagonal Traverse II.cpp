class Solution {
public:
    struct Item {
      int sum,y,data;
      bool operator<(const Item& other) const {
          if (sum < other.sum)
              return true;
          else if (sum == other.sum && y > other.y)
              return true;
          return false;
      }
    };
    
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<Item> vc;
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums[i].size(); j++)
                vc.push_back({i+j,i,nums[i][j]});
        
        sort(vc.begin(), vc.end());
        vector<int> ans;
        for (auto& p : vc)
            ans.push_back(p.data);
        return ans;
    }
};
