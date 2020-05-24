class Solution {
public:
string largestTimeFromDigits(vector<int>& A) {
	unordered_map<int,int> d;
	
	for (int a : A) {
		if (d.find(a) == d.end())
			d[a] = 1;
		else d[a]++;
	}
	
	for (int h = 23; h >= 0; h--) {
		for (int m = 59; m >= 0; m--) {
			unordered_map<int,int> dd = d;
			int h1 = h / 10;
			int h2 = h % 10;
			int m1 = m / 10;
			int m2 = m % 10;
			
			if (dd.find(h1) != dd.end() && dd[h1] > 0) dd[h1]--;
			else continue;
			if (dd.find(h2) != dd.end() && dd[h2] > 0) dd[h2]--;
			else continue;
			
			if (dd.find(m1) != dd.end() && dd[m1] > 0) dd[m1]--;
			else continue;
			if (dd.find(m2) != dd.end() && dd[m2] > 0) dd[m2]--;
			else continue;
			
			return to_string(h1) + to_string(h2) + ":" + to_string(m1) + to_string(m2);
		}
	}
    return "";
}
};
