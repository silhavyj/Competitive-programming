static const auto ____ = [] () {
ios::sync_with_stdio(false);
cin.tie(nullptr);
return nullptr;
}();
class NumMatrix {
	vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
    	for (auto row : matrix) {
    		int sum = 0;
    		vector<int> row_sum;
    		for (int x : row) {
    			sum += x;
    			row_sum.push_back(sum);
    		}
    		this->matrix.push_back(row_sum);
		}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
    	int sum = 0;
    	for (int i = row1; i <= row2; i++) {
    		if (col1 == 0)
    			sum += matrix[i][col2];
    		else sum += matrix[i][col2] - matrix[i][col1-1]; 
		}
    	return sum;
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
