class Solution {
public:
    string convert(string s, int numRows) {
        	
	if (numRows == 1)
		return s;
        
        	int n = s.length();
	int state = 0;
	char zigZag[numRows][n];
	int i=0, j=0, p=0;
	string res = "";
		
	memset(zigZag, ' ', sizeof(zigZag));
	
	while (p < n) {
		zigZag[i][j] = s[p++];
		switch (state) {
			case 0:
				if (i+1 == numRows) {
					i--;
					j++;
					state = 1;
				}
				else i++;
				break;
			case 1:
				if (i-1 == -1) {
					i++;
					state = 0;
				}
				else {
					i--;
					j++;
				}
				break;
		}
	} 
	
	for (i = 0; i < numRows; i++)
		for (j = 0; j < n; j++)
			if (zigZag[i][j] != ' ')
				res += zigZag[i][j];
	return res;
    }
};
