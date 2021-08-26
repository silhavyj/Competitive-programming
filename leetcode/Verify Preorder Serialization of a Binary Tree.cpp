class Solution {
    vector<string> __split(const string& s, char c) {
      vector<string> v;
      stringstream ss(s);
      string x;
      while (getline(ss, x, c))
          if (x!="")
              v.emplace_back(x);
      return move(v);
  }
    
public:
    bool isValidSerialization(string preorder) {
        vector<string> tokens = __split(preorder, ',');
        int d=1;
        for (string x : tokens) {
            d--;
            if (d<0)
                return false;
            if (x!="#")
                d+=2; 
        }
        return d==0;
    }
};
