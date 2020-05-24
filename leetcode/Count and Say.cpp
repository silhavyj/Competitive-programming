class Solution {
public:
string countAndSay(int n) {
	string res = "1";
	if (n == 1)
		return res;
	
	string next;
	char curr;
	int count;
	
	for (int i = 1; i < n; i++) {
		curr = res[0];
		count = 1;
		next = "";
		cout << res << endl;
		
		for (int j = 1; j < res.length(); j++) {
			if (res[j] != curr) {
				next += to_string(count) + curr; 
				count = 1;
				curr = res[j];
			}
			else count++;
		}
		next += to_string(count) + curr; 
		res = next;
	}
	return res;
}
};
