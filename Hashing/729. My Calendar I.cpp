class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        st.clear();
    }
    
    bool book(int start, int end) {
        
        for(auto x: st){
            int s = x.first, e = x.second;
            
            if(!(end <= s || start >= e)){
                return false;
            }
        }
        st.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
