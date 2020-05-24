#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define debug(args...) \
cout << "#" << __LINE__ << ": "; \
__dbg(split(#args, ',').begin(), args);
vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}
template<typename T, typename... Args>
inline string to_str(T x) {
	stringstream ss; ss << "[";
	for (auto it = x.begin(); it != x.end(); it++) {
		if (it != x.begin()) ss << " ";
		ss << (*it);
	}
	ss << "]";
	return ss.str();
}
template<typename T>
inline string to_str(stack<T> x) {
	stringstream ss; ss << "[";
	bool first = 1;
	while (!x.empty()) {
		if (!first)
			ss << " ";
		ss << x.top();
		x.pop();
		first = 0;
	}
	ss << "]";
	return ss.str();
}
template<typename T1, typename T2>
ostream &operator<<(ostream &ostr, const pair<T1,T2> p) {
	ostr << "(" << p.first << "," << p.second << ")";
	return ostr;
}
template<typename T> inline void __dbg_var(vector<T> x) { cout << to_str(x); }
template<typename T> inline void __dbg_var(list<T> x) { cout << to_str(x); }
template<typename T> inline void __dbg_var(set<T> x) { cout << to_str(x); }
template<typename T> inline void __dbg_var(unordered_set<T> x) { cout << to_str(x); }
template<typename T> inline void __dbg_var(stack<T> x) { cout << to_str(x); }
template<typename T> inline void __dbg_var(T val) { cout << val; }
inline void __dbg(vector<string>::iterator it) { cout << endl; }
template<typename T, typename... Args>
inline void __dbg(vector<string>::iterator it, T a, Args... args) {
	cout << it->substr((*it)[0] == ' ', it->length()) << "=";
	__dbg_var(a);
	cout << " ";
	__dbg(++it, args...);
}
/*******************PROGRAM STARTS HERE*********************/

int moves[4][2] = {
	{-1,0},
	{1,0},
	{0,1},
	{0,-1}
};

void solve(int n, int m) {
	char grid[n][m];
	vector<pair<int,int>> dirty;
	pair<int,int> start;
	
	// store the grid into the array as well as the robot's position
	// and all the dirty spots
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j]=='*')
				dirty.push_back({i,j});
			else if (grid[i][j]=='o')
				start = make_pair(i,j);
		}
	}
	
	// let's consider the robot's position
	// as one of the dirty spots - we know
	// his position in the array is 0
	dirty.insert(dirty.begin(),start);
	
	// final array where we store all the distances
	// from all the dirty spots to the rest of them
	// (including the robot)
	int dis[dirty.size()][dirty.size()];
	
	// run a bfs from all the positions to all
	// the other positions	
	for (int l = 0; l < (int)dirty.size(); l++) {
		
		// temporary array to store distances from
		// the current spot to all the other spots
		// initially it's all infinity
		int d[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				d[i][j] = INT_MAX;
				
		// run the bfs from the current position
		// the distance from the current distant to the
		// current distance is 0, add it to the queue
		d[dirty[l].first][dirty[l].second]=0;
		queue<pair<int,int>> que;
		que.push({dirty[l].first,dirty[l].second});
		
		//bfs
		while (!que.empty()) {
			auto top = que.front();
			que.pop();
			// go over all directions (W,S,N,E)
			for (int k = 0; k < 4; k++) {
				// create a potentional position
				int y = top.first + moves[k][0];
				int x = top.second + moves[k][1];
				
				// make sure you're not off the grid
				if (y < 0 || x < 0 || y >= n || x >= m)
					continue;
					
				// make sure you haven't seen that position yet
				// and it's reachable (there is no wall - 'x')
				if (d[y][x]!=INT_MAX || grid[y][x]=='x')
					continue;
					
				// if it's all good - update the new positon
				// the distance is the distance so far + 1 step
				d[y][x] = d[top.first][top.second] + 1;
				que.push({y,x});
			}
		}
		
		// when you got all the distances from the current position
		// to all the other positions, update the final matrix of distances
		for (int q = 0; q < (int)dirty.size(); q++)
			// the distance from the current position to the current
			// position is obviously 0 -> don't need to update that
			if (q!=l)
				dis[l][q]=d[dirty[q].first][dirty[q].second];
	}
	
	// unfortunately we need to generate all permutations
	// except the robot's position (0th)
	// so the arry looks like 1 2 3 4 ... n, where n is the
	// number of dirty spots 
	vector<int> p;
	for (int i = 1; i < (int)dirty.size(); i++)
		p.push_back(i);
	
	// the minimal path
	int ans = INT_MAX;
	// current path
	ll path;
	do {
		path = 0;
		// you need to make sure that you always start
		// at the robot's position firt 
		path = dis[0][p[0]];
		
		// then you go spot by spot and take the distance
		// between them from the final matrix of all distances
		// for example, the current permutation is 2 3 1 4
		// so you need the distance from 2 to 3 then from 3 to 1 and so on
		for (int i = 0; i < (int)p.size()-1; i++) {
			path += dis[p[i]][p[i+1]];
			if (path >= INT_MAX) {
				cout << "-1\n";
				return;
			}
		}
			
		// update the minimal path
		ans = min(ans, (int)path);
		
		// generate the next permutation
		// c++ takes care of it automatically
	} while (next_permutation(p.begin(),p.end()));
	
	// print out the result
	if (ans == INT_MAX)
		cout << "-1\n";
	else cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	while (n || m) {
		solve(m,n);
		cin >> n >> m;
	}	
	return 0;
}
