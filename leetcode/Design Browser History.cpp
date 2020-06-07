class BrowserHistory {
    vector<string> pages;
    int p;
public:
    BrowserHistory(string homepage) {
        pages.push_back(homepage);
        p = 0;
    }
    
    void visit(string url) {
        pages.erase(pages.begin()+p+1, pages.end());
        pages.push_back(url);
        p++;
    }
    
    string back(int steps) {
        for (int i = 0; i < steps; i++) {
            if (p == 0)
                break;
            p--;
        }
        return pages[p];
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (p == pages.size()-1)
                break;
            p++;
        }
        return pages[p];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
