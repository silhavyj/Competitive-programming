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
template<typename T> inline void __dbg_var(vector<T> x) { cout << to_str(x); }
template<typename T> inline void __dbg_var(list<T> x) { cout << to_str(x); }
template<typename T> inline void __dbg_var(set<T> x) { cout << to_str(x); }
template<typename T> inline void __dbg_var(unordered_set<T> x) { cout << to_str(x); }
template<typename T> inline void __dbg_var(T val) { cout << val; }
inline void __dbg(vector<string>::iterator it) { cout << endl; }
template<typename T, typename... Args>
inline void __dbg(vector<string>::iterator it, T a, Args... args) {
	cout << it->substr((*it)[0] == ' ', it->length()) << "=";
	__dbg_var(a);
	cout << " ";
	__dbg(++it, args...);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
			
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		ll available = (ll)n*m;
		ll edges = (ll)n*(m-1)+(ll)m*(n-1);
		//debug(edges, available);
		if (edges > available)
			cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
