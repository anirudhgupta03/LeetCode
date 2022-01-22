class Solution {
public:
    void solve(int num, int n, vector<int> &v){
        
        if(num > n){
            return;
        }
        v.push_back(num);
        for(int i = 0; i < 10; i++){
            solve(10*num + i, n, v);
        }
    }
    vector<int> lexicalOrder(int n) {
        
        vector<int> v;
        
        for(int i = 1; i <= 9; i++){
            solve(i, n, v);
        }
        return v;
    }
};
