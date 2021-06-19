class Solution {
private:
vector<string> __split(const string& s, char c) {
    vector<string> v;
    stringstream ss(s);
    string x;
    while (getline(ss, x, c))
        if (x != "")
            v.emplace_back(x);
    return move(v);
}
public:
    string simplifyPath(string path) {
        string ans = "/";
        vector<string> tokens = __split(path, '/');

        string curr = "";
        for (string t : tokens) {
            if (t==".")
                continue;
            else if (t=="..") {
                int last_p = curr.find_last_of("/");
                curr = curr.substr(0,last_p);
            } else {
                curr += "/" + t;
            }
        }
        return curr == "" ? "/" : curr;
    }
};
