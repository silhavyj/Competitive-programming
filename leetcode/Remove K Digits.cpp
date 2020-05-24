class Solution {
public:
string removeKdigits(string num, int k) {
	if (k==0)
		return num;
		
	if (k==num.length())
		return "0";
	
	stack<int> st;
	for (char c : num) {
		while (!st.empty() && k && (c-'0') < st.top()) {
			st.pop();
			k--;
		}
		st.push(c-'0');
	}
	for (; k; k--)
		st.pop();
	string ans = "";
	while (!st.empty()) {
		ans.insert(ans.begin(),'0'+st.top());
		st.pop();
	}
	while (ans[0]=='0')
		ans.erase(0,1);
	return ans.size() != 0 ? ans : "0";
}
};
