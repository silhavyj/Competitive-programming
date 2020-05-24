class Solution {
public:
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    vector<string> lineWords;
    int totalLen = 0;
    int len = 0;
    
    for (int i = 0; i < words.size(); ) {
    	if (totalLen + words[i].length() <= maxWidth) {
    		lineWords.push_back(words[i]);
    		len += words[i].length();
    		totalLen += words[i].length();
    		if (len < maxWidth)
    			totalLen++;
    		i++;
		}
		else {
			if (lineWords.size() == 1) {
				string line = lineWords[0];
				for (int i = lineWords[0].length(); i < maxWidth; i++)
					line += " ";
				res.push_back(line);
			}
			else {
				int spaces = (maxWidth - len) / (lineWords.size()-1);
				int extraSpaces = (maxWidth - len) % (lineWords.size()-1);
				string line = "";
				
				for (int i = 0; i < lineWords.size(); i++) {
					line += lineWords[i];
					if (i < lineWords.size()-1) {
						if (extraSpaces-- > 0)
							line += " ";
						for (int j = 0; j < spaces; j++)
							line += " ";
					}
				}
				res.push_back(line);
			}
			totalLen = 0;
			len = 0;
			lineWords.clear();	
		}
	}
	if (lineWords.size()) {
		string line = "";
		int count = 0;
		for (int i = 0; i < lineWords.size(); i++) {
			line += lineWords[i];
			count += lineWords[i].size();
			if (i < lineWords.size() - 1) {
				line += " ";
				count++;
			}
		}
		for (int i = count; i < maxWidth; i++)
			line += " ";
		res.push_back(line);
	}
    return res;
}

};
