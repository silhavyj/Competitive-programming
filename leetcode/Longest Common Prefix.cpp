class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        	int p = 0;
	if (strs.size() == 0)
		return "";
	if (strs.size() == 1)
		return strs[0];
	
	while (1) {
		cout << p << endl;
		for (int i = 0; i < strs.size() - 1; i++) {
			if (p >= strs[i].length())
				return strs[i];
			if (strs[i][p] != strs[i+1][p])
				return strs[i].substr(0, p);
		}
		p++;
	}      
    }
};
