class Solution {
public:
bool found = false;
int moves[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
set<pair<int,int>> used;

void solve(vector<vector<char>>& board, int i, int j, string &word, int p, int n, int m) {
	if (board[i][j] != word[p])
		return;
	
	pair<int,int> pos = make_pair(i,j);
	if (used.find(pos) != used.end())
		return;
		
	used.insert(pos);
		
	if (p == word.length()-1) {
		found = true;
		return;
	}
	for (int k = 0; k < 4; k++) {
		int y = i + moves[k][0];
		int x = j + moves[k][1];
		if (y < 0 || x < 0 || x >= m || y >= n)
			continue;
			
		solve(board, y,x,word,p+1,n,m);
		if (found == true)
			return;
	}
    used.erase(pos);
}

bool exist(vector<vector<char>>& board, string word) {
	int n = board.size();
	int m = board[0].size();
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)  {
			if (board[i][j] == word[0]) {
				used.clear();
				solve(board, i,j, word, 0, n,m);
			}
			if (found)
				return true;
		}
	}
	return false;
}
};
