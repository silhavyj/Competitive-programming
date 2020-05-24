class Solution {
public:
unordered_set<string> res;

void solve(string &tiles, bool *used, string s) {
	if (s != "")
		res.insert(s);
	for (int i = 0; i < tiles.size(); i++) {
		if (used[i] == false) {
			used[i] = true;
			solve(tiles, used, s + tiles[i]);
			used[i] = false;
		}
	}
}

int numTilePossibilities(string tiles) {
	bool used[tiles.size()];
	memset(used, false, tiles.size());
	solve(tiles, used, "");
	return res.size();
}
};
