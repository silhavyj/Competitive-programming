class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	int a = 0, b = 0;
	int res = 0;
	int n = s.length();
	unordered_set<char> uniq;
	
	while (a < n && b < n) {
		if (uniq.find(s[a]) == uniq.end()) {
			uniq.insert(s[a++]);
			res = max(res, a-b);
		}
		else uniq.erase(s[b++]);
	} 
	return res;
    }
};
