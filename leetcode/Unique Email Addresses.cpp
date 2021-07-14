class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (string email : emails) {
            bool seenAt = false;
            int i = 0;
            while (i < email.length()) {
                if (email[i]=='@') {
                    seenAt = true;
                    i++;
                } else if (seenAt == false) {
                    if (email[i]=='.') {
                        email = email.substr(0,i) + email.substr(i+1,email.length());
                        i--;
                    } else if (email[i]=='+') {
                        int p = i+1;
                        while (email[p]!='@')
                            p++;
                        email = email.substr(0,i) + email.substr(p,email.length());
                        break;
                    }
                    else i++;
                } else break;
            }
            s.insert(email);
        }
        return s.size();
    }
};
