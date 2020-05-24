class Solution {
public:
vector<int> countBits(int num) {
    vector<int> res; 
    int p = 1;
    res.push_back(0);
    
    for (int i = 1; i <= num; i++) {
    	if (2*p == i) {
    		res.push_back(1);
    		p *= 2;
		}
		else res.push_back(1 + res[i-p]);
	}
    return res;
}
};
