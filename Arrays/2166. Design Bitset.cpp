class Bitset {
public:
    vector<int> bits;
    int ones, zeros, flips, n ;
    Bitset(int size) {
        bits.resize(size, 0);
        ones = 0;
        zeros = size;
        flips = 0;
        n = size;
    }
    
    void fix(int idx) {
        if(flips % 2 == 0){
            if(bits[idx] == 0){
                zeros--;
                ones++;
            }
            bits[idx] = 1;
        }
        else{
            if(bits[idx] == 1){
                zeros--;
                ones++;
            }
            bits[idx] = 0;
        }
    }
    
    void unfix(int idx) {
        if(flips % 2 == 0){
            if(bits[idx] == 1){
                ones--;
                zeros++;
            }
            bits[idx] = 0;
        }
        else{
            if(bits[idx] == 0){
                ones--;
                zeros++;
            }
            bits[idx] = 1;
        }
    }
    
    void flip() {
        flips++;
        swap(ones, zeros);
    }
    
    bool all() {
        if(ones == n){
            return true;
        }
        return false;
    }
    
    bool one() {
        if(ones) return true;
        return false;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        string res;
        for(int i = 0; i < n; i++){
            if(flips % 2 == 0){
                res.push_back(bits[i] + '0');
            }
            else{
                res.push_back((1 - bits[i]) + '0');
            }
        }
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
