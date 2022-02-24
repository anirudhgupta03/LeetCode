class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind;
    StockSpanner() {
        ind = 0;
    }
    
    int next(int price) {
        int ans = 0;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        if(st.empty()){
            ans = ind + 1;
        }
        else{
            ans = ind - st.top().second; 
        }
        st.push({price, ind});
        ind++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
