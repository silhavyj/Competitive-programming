class Solution {
public:
vector<string> res;

void getAllPerm(vector<string> comb, int index, string r) {
	if (index == comb.size()) {
		res.push_back(r);
		return;
	}
	for (char c : comb[index])
		getAllPerm(comb, index + 1, r + c);
}

vector<string> letterCombinations(string digits) {
    if (digits.length() == 0)
        return res;
    
    unordered_map<int, string> buttons;
        
	buttons[2] = "abc";
    buttons[3] = "def";
    buttons[4] = "ghi";
    buttons[5] = "jkl";
    buttons[6] = "mno";
    buttons[7] = "pqrs";
    buttons[8] = "tuv";
    buttons[9] = "wxyz";
            
    vector<string> comb;
    for (char d : digits)
        comb.push_back(buttons[(int)d-48]);   	
        
    getAllPerm(comb, 0, "");
    return res;
}
};
