class Solution {
    struct TrieNode {
        int v;
        TrieNode *next[26];
        TrieNode() : v(0) {
            memset(next, NULL, sizeof(next));
        }
    };
    
    int move[4][2] = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };
    
    void solve(int y, int x, vector<vector<char>>& board, TrieNode *node, vector<string> &ans, string &curr) {
        char tmp=board[y][x];
        board[y][x]='#';
        node = node->next[tmp-'a'];
        if (node->v > 0) {
            ans.push_back(curr);
            node->v--;
        }
        for (int i=0; i<4; ++i) {
            int yy = y+move[i][0];
            int xx = x+move[i][1];
            if (yy < 0 || yy >= board.size() || xx < 0 || xx >= board[0].size())
                continue;
            if (board[yy][xx]!='#' && node->next[board[yy][xx]-'a']) {
                curr.push_back(board[yy][xx]);
                solve(yy,xx,board,node,ans,curr);
                curr.pop_back();
            }
        }
        board[y][x]=tmp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || words.empty())
            return vector<string>();
        TrieNode *root = new TrieNode();
        for (string word : words) {
            TrieNode *tmp=root;
            for (char c : word) {
                if (!tmp->next[c-'a'])
                    tmp->next[c-'a'] = new TrieNode();
                tmp = tmp->next[c-'a'];
            }
            tmp->v++;
        }
        vector<string> ans;
        ans.reserve(words.size());
        int n = board.size();
        int m = board[0].size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (root->next[board[i][j]-'a']) {
                    string curr="";
                    curr.push_back(board[i][j]);
                    solve(i,j,board,root,ans,curr);
                }
            }
        }
        return ans;
    }
};
