class Solution {
public:
    
    int moves[8][2] = {
        {-1,-1},
        {-1,0},
        {-1,1},
        {0,1},
        {1,1},
        {1,0},
        {1,-1},
        {0,-1}
    };
    
    int countNeighbors(vector<vector<int>>& board, int y, int x) {
        int neighs = 0;
        for (int i = 0; i < 8; i++) {
            int yy = y + moves[i][0];
            int xx = x + moves[i][1];
            if (yy < 0 || xx < 0 || yy >= board.size() || xx >= board[0].size())
                continue;
            if (board[yy][xx] == 1)
                neighs++;
        }
        return neighs;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>> dead, alive;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int neighs = countNeighbors(board,i,j);
                if (board[i][j] == 1 && (neighs < 2 || neighs > 3))
                    dead.push_back({i,j});
                if (board[i][j] == 0 && neighs == 3)
                    alive.push_back({i,j}); 
            }
        }
        for (auto p : dead) board[p.first][p.second] = 0;
        for (auto p : alive) board[p.first][p.second] = 1;
    }
};
