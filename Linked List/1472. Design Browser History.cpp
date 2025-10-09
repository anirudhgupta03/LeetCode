class BrowserHistory {

struct ListNode{
    ListNode* pre, *next;
    string page;
    ListNode(string p){
        page = p;
        pre = NULL;
        next = NULL;
    }
};

public:
    ListNode *curr;
    BrowserHistory(string homepage) {
        curr = new ListNode(homepage);
    }
    
    void visit(string url) {
        ListNode* website = new ListNode(url);
        curr -> next = website;
        website -> pre = curr;
        curr = website;
    }
    
    string back(int steps) {
        while(curr && curr -> pre && steps){
            curr = curr -> pre;
            steps--;
        }
        return curr -> page;
    }
    
    string forward(int steps) {
        while(curr && curr -> next && steps){
            curr = curr -> next;
            steps--;
        }
        return curr -> page;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
