class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int s = n / 2;
                
        for (int p = 0; p < s; p++) {
        	for (int i = p; i < n-p-1; i++) {
        		int& a = matrix[p][i];
        		int& b = matrix[i][n-p-1];
			int& c = matrix[n-p-1][n-i-1];
        		int& d = matrix[n-i-1][p];
        		
        		int tmp = a;
        		a = d;
        		d = c;
        		c = b;
        		b = tmp;
			}
		}	
    }
};
