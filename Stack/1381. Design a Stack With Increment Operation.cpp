class CustomStack {
public:
    vector<int> v;
    int ind;
    CustomStack(int maxSize) {
        ind = 0;
        v.clear();
        v.resize(maxSize);
    }
    
    void push(int x) {
        if(ind < v.size()){
            v[ind] = x;
            ind++;
        }
    }
    
    int pop() {
        if(ind == 0){
            return -1;
        }
        int ele = v[ind - 1];
        ind--;
        return ele;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, ind); i++){
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
