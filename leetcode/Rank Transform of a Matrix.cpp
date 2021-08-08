class Solution {
    pair<int,int> par[501][501];
    int rank[501][501];
    
    pair<int,int> _find(pair<int,int> a) {
        if (par[a.first][a.second] == a)
            return a;
        par[a.first][a.second] = _find(par[a.first][a.second]);
        return par[a.first][a.second];
    }
    
    void _union(pair<int,int> a, pair<int,int> b) {
        a = _find(a);
        b = _find(b);
        if (rank[a.first][a.second] > rank[b.first][b.second]) {
            par[b.first][b.second] = a;
            rank[a.first][a.second]++;
        } else {
            par[a.first][a.second] = b;
            rank[b.first][b.second]++;
        }
    }
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                par[i][j] = {i,j};
                rank[i][j] = 1;
            }
        
        for (int i = 0; i < n; i++) {
            map<int, pair<int,int>> mp;
            for (int j = 0; j < m; j++) {
                if (mp.find(matrix[i][j]) != mp.end()) {
                    _union({i,j},mp[matrix[i][j]]);
                } else {
                    mp[matrix[i][j]] = {i,j};
                }
            }
        }
        
        for (int j = 0; j < m; j++) {
            map<int, pair<int,int>> mp;
            for (int i = 0; i < n; i++) {
                if (mp.find(matrix[i][j]) != mp.end()) {
                    _union({i,j},mp[matrix[i][j]]);
                } else {
                    mp[matrix[i][j]] = {i,j};
                }
            }
        }
        
        vector<pair<int,int>> v[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto x = _find({i,j});
                v[x.first][x.second].push_back({i,j});
            }
        }
        
        map<int, vector<vector<pair<int,int>>>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j].size()==0)
                    continue;
                mp[matrix[i][j]].push_back(v[i][j]);
            }
        }
        vector<int> row(n,0), col(m,0);
        for (auto a : mp) {
            auto l = a.second;
            for (auto u : l) {
                int x = 0;
                for (auto v : u) {
                    x = max(x, 1+max(row[v.first], col[v.second]));
                }
                for (auto v : u) {
                    ans[v.first][v.second] = x;
                    row[v.first] = max(x, row[v.first]);
                    col[v.second] = max(x, col[v.second]);
                }
            }
        }
        return ans;
    }
};
