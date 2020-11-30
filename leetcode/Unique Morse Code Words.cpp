class Solution {
public:
    
    string morse[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."}; 
    
    int uniqueMorseRepresentations(vector<string>& words) {
        map<string, list<string>> mp;
        for (string word : words) {
            string k = "";
            for (char c : word)
                k += morse[c-'a'];
            mp[k].push_back(word);
        }
        return mp.size();
    }
};
