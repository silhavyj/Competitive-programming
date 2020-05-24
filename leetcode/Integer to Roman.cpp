class Solution {
public:
    string intToRoman(int num) {
	int vals[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
	string marks[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
	string res = "";
	
	for (int i = 12; i >= 0; i--) {
		int k = num / vals[i];
		int c = k;
		if (k > 0) {
			while (c--)
				res += marks[i];
			num -= k * vals[i];
			if (num == 0)
				return res;
		}
	}
	return res;
    }
};
