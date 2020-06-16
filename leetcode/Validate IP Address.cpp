class Solution {
public:
    vector<string> __split(const string& s, char c) {
	    vector<string> v;
	    stringstream ss(s);
	    string x;
	    while (getline(ss, x, c))
		    v.emplace_back(x);
	    return move(v);
    }
    
    string validIPAddress(string IP) {
        vector<string> parts;
        bool ipv4 = true;
        int dots = 0;
        int semicolons = 0;
        for (char c : IP) {
            dots += c=='.';
            semicolons += c==':';
        }
        if (!((dots==0 && semicolons==7) || (semicolons==0 && dots==3)))
             return "Neither";
        parts = __split(IP, dots==0 ? ':' : '.');
        ipv4 = semicolons == 0;
        if ((ipv4 && parts.size() != 4) || (!ipv4 && parts.size() != 8))
            return "Neither";
        for (string s : parts) {
            try { 
                int num;
                if (ipv4) {
                    if (s[0]=='0')
                        return "Neither";
                    for (char c : s)
                        if (!(c>='0'&&c<='9'))
                            return "Neither";
                    num = stoi(s);
                    if (num > 255)
                        return "Neither";
                }
                else {
                    if (s.length() > 4)
                        return "Neither";
                    num = stoi(s, 0, 16);
                    if (num > 65535)
                        return "Neither";
                }
            }
            catch (invalid_argument const& e) {
                return "Neither";
            }
            catch (out_of_range const& e) {
                return "Neither";
            }
        }
        return ipv4 ? "IPv4" : "IPv6";
    }
};
