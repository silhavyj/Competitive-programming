#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Conf {
	int wheels[4];
	Conf(){}
	Conf(const Conf& other) {
		memcpy(this, &other, sizeof(Conf));
	}
	bool operator==(const Conf& other) const {
		for (int i = 0; i < 4; i++)
			if (wheels[i] != other.wheels[i])
				return false;
		return true;
	}
	Conf operator>>(int p) {
		Conf conf(*this);
		conf.wheels[p]++;
		if (conf.wheels[p]==10)
			conf.wheels[p]=0;
		return conf;
	}
	Conf operator<<(int p) {
		Conf conf(*this);
		conf.wheels[p]--;
		if (conf.wheels[p]==-1)
			conf.wheels[p]=9;
		return conf;
	}
};

struct ConfHash {
	size_t operator()(const Conf& conf) const {
		int h = 31;
		for (int i = 0; i < 4; i++)
			h = 17 * h + conf.wheels[i];
		return h;
	}
};

istream& operator>>(istream &in, Conf& conf) {
	in >> conf.wheels[0] >> conf.wheels[1] >>
		  conf.wheels[2] >> conf.wheels[3];
	return in;
}

//just for debugging
ostream& operator<<(ostream& out, Conf& conf) {
	out << "[";
	for (int i = 0; i < 4; i++) {
		out << conf.wheels[i];
		if (i != 3)
			out << " ";
	}
	out << "]";
	return out;
}

void solve() {
	int n;
	Conf s,e,f;
	unordered_set<Conf,ConfHash> forbidden;
	unordered_map<Conf,int,ConfHash> mp;
	queue<Conf> que;
	bool found=false;
	
	cin >> s >> e;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> f;
		forbidden.insert(f);
	}
	que.push(s);
	mp[s]=0;
	while (!que.empty()) {
		Conf t = que.front();
		//cout << t << endl;
		que.pop();
		if (t==e) {
			found=true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			Conf up = t>>i;
			Conf down = t<<i;
			if (forbidden.find(up) == forbidden.end() && mp.find(up) == mp.end()) {
				mp[up] = mp[t] + 1;
				que.push(up);
			}
			if (forbidden.find(down) == forbidden.end() && mp.find(down) == mp.end()) {
				mp[down] = mp[t] + 1;
				que.push(down);
			}
		}
	}
	if (found)
		cout << mp[e] << "\n";
	else cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	string line;
	cin >> t;
	while (t--) {
		getline(cin,line);
		solve();
		cin.ignore();
	}
	return 0;
}
