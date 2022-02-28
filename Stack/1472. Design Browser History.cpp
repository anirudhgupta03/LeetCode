class BrowserHistory {
public:
    int ind;
    vector<string> v;
    BrowserHistory(string homepage) {
        v.clear();
        v.push_back(homepage);
        ind = 0;
    }
    
    void visit(string url) {
        int tind = v.size() - 1;
        while(tind > ind){
            v.pop_back();
            tind--;
        }
        v.push_back(url);
        ind++;
    }
    
    string back(int steps) {
        while(ind != 0 && steps != 0){
            steps--;
            ind--;
        }
        return v[ind];
    }
    
    string forward(int steps) {
        while(ind != v.size() - 1 && steps != 0){
            steps--;
            ind++;
        }
        return v[ind];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
