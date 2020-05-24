#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	list<char> l;
	list<char>::iterator it;
	string str;
	
	while (cin >> str) {
		l.clear();
		it = l.begin();
		for (char c : str) {
			if (c==']')
				it = l.end();
			else if (c=='[')
				it = l.begin();
			else l.insert(it,c);
		}
		for (char c : l)
			cout << c;
		cout << "\n";
	}
	return 0;
}
