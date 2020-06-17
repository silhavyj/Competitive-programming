class Solution {
public:
    
    set<pair<int,int>> area;
    bool flip=true;
    int moves[4][2] = {
        {-1,0},
        {1,0},
        {0,1},
        {0,-1}
    };
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        //cout << i << " " << j << endl;
        if (i==0 || j==0 || i == board.size()-1 || j == board[0].size()-1)
            flip = false;
        if (flip == false)
            return;
        area.insert({i,j});
        for (int k = 0; k < 4; k++) {
            int y = i + moves[k][0];
            int x = j + moves[k][1];
            if (y < 0 || x < 0 || y >= board.size() || x >= board[0].size())
                continue;
            if (area.count({y,x})!=0)
                continue;
            if (board[y][x]=='O')
                dfs(board,y,x);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j]=='O') {
                    area.clear();
                    flip=true;
                    dfs(board,i,j);
                    if (flip) 
                        for (auto a : area)
                            board[a.first][a.second] = 'X';
                }
    }
};
