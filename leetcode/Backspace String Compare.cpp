class Solution {
public:
    
string getString(string S) {
	stack<char> s;
	string ans = "";
	
	for (char c : S) {
		if (c != '#')
			s.push(c);
		else if (!s.empty())
			s.pop();
	}
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	return ans;
}
    
bool backspaceCompare(string S, string T) {
    return getString(S) == getString(T);
}
};
