class Solution {
public:
string getNum(string s, int from, int to, bool isHour) {
	int res = 0;
	int p = 1;
	
	for (int i = to; i >= from; i--) {
		if (s[i] == '1')
			res |= p;
		p <<= 1;
	}
	if (!isHour && res >= 12)
		return "";
    if (isHour && res >= 60)
        return "";
		
	if (res < 10 && isHour)
		return "0" + to_string(res);
	return to_string(res);
}

vector<string> ans;

void solve(string curr, int ones, int target) {
	if (curr.size() == 10) {
		if (ones == target) {
			//string res = getNum(curr, 4, 9, false) + ":" + getNum(curr, 0, 3, true);
			//ans.insert(ans.begin(), res);
			string h = getNum(curr, 4, 9, true);
            string m = getNum(curr, 0, 3, false);
			if (m == "" || h == "")
				return;
			string res = m + ":" + h;
			ans.push_back(res);
		}
		return;
	}
	solve(curr + "0", ones, target);
	solve(curr + "1", ones + 1, target);	
}

vector<string> readBinaryWatch(int num) {
    solve("", 0, num);
    return ans;
}
};
