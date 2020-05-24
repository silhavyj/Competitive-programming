class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        vector<int> rows, cols;
        
        for (int i = 0; i < matrix.size(); i++) {
        	int minRow = 0;
        	for (int j = 0; j < matrix[i].size(); j++) {
        		if (matrix[i][j] < matrix[i][minRow])
        			minRow = j;
        		if (!i)
					cols.push_back(matrix[i][j]);
				else cols[j] = max(cols[j], matrix[i][j]);
			}
			rows.push_back(minRow);
		}
		
		for (int i = 0; i < rows.size(); i++)
			if (matrix[i][rows[i]] == cols[rows[i]])
				res.push_back(cols[rows[i]]);
        return res;
    }
};
