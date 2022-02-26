//Method - 1
//TC - O(N)
//SC - O(N)
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

//Method - 2
//Ref: https://www.youtube.com/watch?v=-CXN5Nh9jOA
//TC - O(1)
//SC - O(N)
class CustomStack {
public:
    vector<int> v;
    vector<int> inc;
    int ind;
    CustomStack(int maxSize) {
        ind = 0;
        v.clear();
        inc.clear();
        inc.resize(maxSize,0);
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
        int temp = inc[ind - 1];
        int ele = v[ind - 1] + inc[ind - 1];
        inc[ind - 1] = 0;
        ind--;
        if(ind != 0)
        inc[ind - 1] += temp;
        return ele;
    }
    
    void increment(int k, int val) {
        if(ind - 1 != -1)
        inc[min(k - 1, ind - 1)] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
