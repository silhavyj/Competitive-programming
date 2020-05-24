class Solution {
public:
    
    vector<pair<int,int>> pos;
    bool solved = false;
    
    bool checkLines(vector<vector<char>>& board, int index, char val) {
        int y = pos[index].first;
        int x = pos[index].second;
        
        for (int i = 0; i < 9; i++)
            if ((i != x && board[y][i] == val) ||
                (i != y && board[i][x] == val))
                return false;
        return true;
    }
    
    bool checkSquare(vector<vector<char>>& board, int index, char val) {
        int y = pos[index].first;
        int x = pos[index].second;
        
        int sy = (y / 3) * 3;
        int sx = (x / 3) * 3;
        
        for (int i = sy; i < sy + 3; i++)
            for (int j = sx; j < sx + 3; j++)
                if (i != y && j != x && board[i][j] == val)
                    return false;
        return true;
    }
    
    void solve(vector<vector<char>>& board, int index) {
        if (index == pos.size()) {
            solved = true;
            return;
        }
        int y = pos[index].first;
        int x = pos[index].second;
        for (char i = '1'; i <= '9'; i++) {
            if (!checkLines(board, index, i))
                continue;
            
            if (!checkSquare(board, index, i))
                continue;
            
            board[y][x] = i;
            solve(board, index + 1);
            if (solved)
                return;
            board[y][x] = '.';
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    pos.push_back(make_pair(i,j));
        
        solve(board, 0);
    }  
};
