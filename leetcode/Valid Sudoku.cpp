class Solution {
public:
    
    unordered_set<char> visited;
    char curr;
    
    bool checkLine(vector<vector<char>>& board, bool vertical) {        
        for (int i = 0; i < 9; i++) {
            visited.clear();
            for (int j = 0; j < 9; j++) {
                curr = vertical ? board[j][i] : board[i][j];
                if (curr == '.')
                    continue;
                if (visited.find(curr) != visited.end())
                    return false;
                visited.insert(curr);
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        if (!checkLine(board, true) || !checkLine(board, false))
            return false;
        
        int y = 0, x = 0;
    
        for (int ki = 0; ki < 3; ki++) {
            for (int kj = 0; kj < 3; kj++) {
                visited.clear();
                for (int i = y; i < y+3; i++) {
                    for (int j = x; j < x+3; j++) {
                        curr = board[i][j];
                        if (curr == '.')
                            continue;
                        if (visited.find(curr) != visited.end())
                            return false;
                        visited.insert(curr);
                    }
                }
                x += 3;
            }
            y += 3;
            x = 0;
        }
        return true;
    }
};
