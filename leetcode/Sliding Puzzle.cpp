class Solution {
    struct Puzzle {
        #define N 2
        #define M 3
        int y=0, x=0;
        int board[N][M];
        
        Puzzle(vector<vector<int>>& b) {
             for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++) {
                    if (b[i][j]==0) {
                        y=i;
                        x=j;
                    }
                    board[i][j] = b[i][j];
                }
        }
        
        Puzzle(const Puzzle &other) {
            y=other.y;
            x=other.x;
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    board[i][j] = other.board[i][j];
        }
        
        int moveLeft() {
            if (x > 0) {
                board[y][x] = board[y][x-1];
                x--;
                board[y][x] = 0;
                return 1;
            }
            return 0;
        }
        
        int moveRight() {
            if (x < M-1) {
                board[y][x] = board[y][x+1];
                x++;
                board[y][x] = 0;
                return 1;
            }
            return 0;
        }
        
        int moveUp() {
            if (y > 0) {
                board[y][x] = board[y-1][x];
                y--;
                board[y][x] = 0;
                return 1;
            }
            return 0;
        }
        
        int moveDown() {
            if (y < N-1) {
                board[y][x] = board[y+1][x];
                y++;
                board[y][x] = 0;
                return 1;
            }
            return 0;
        }
        
        bool done() {
            return board[0][0] == 1 &&
                   board[0][1] == 2 &&
                   board[0][2] == 3 &&
                   board[1][0] == 4 &&
                   board[1][1] == 5 &&
                   board[1][2] == 0;
        }
        
        bool operator==(const Puzzle& other) const {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    if (board[i][j] != other.board[i][j])
                        return false;
            return true;
        }
        
        void print() {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++)
                    cout << board[i][j];
                cout << "\n";
            }
            cout << "\n";
        }
    };
    
    struct PuzzleHash {
        size_t operator()(const Puzzle &puzzle) const {
            size_t h = 17;
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    h = 31 * h + puzzle.board[i][j];
            return h;
        }
    };
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        Puzzle initial(board);
        unordered_map<Puzzle, int, PuzzleHash> seen;
        queue<Puzzle> que;
        que.push(initial);
        seen[initial]=0;
        
        while (!que.empty()) {
            auto t = que.front();
            que.pop();
            //t.print();
            if (t.done())
                return seen[t];
            Puzzle next = t;
            if (next.moveLeft() && !seen.count(next)) {
                que.push(next);
                seen[next] = 1 + seen[t];
            }
            next = t;
            if (next.moveRight() && !seen.count(next)) {
                que.push(next);
                seen[next] = 1 + seen[t];
            }
            next = t;
            if (next.moveUp() && !seen.count(next)) {
                que.push(next);
                seen[next] = 1 + seen[t];
            }
            next = t;
            if (next.moveDown() && !seen.count(next)) {
                que.push(next);
                seen[next] = 1 + seen[t];
            }
        }
        return -1;
    }
};
