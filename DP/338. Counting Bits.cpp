//Method - 1
class Solution {
public:
    vector<int> countBits(int num) {
        
       vector<int> res(num+1);
        
        res[0] = 0;
        
        for(int i = 1; i <= num; i++){
            if(i % 2 == 0){
                res[i] = res[i/2];
            }
            else{
                res[i] = res[i/2] + 1;
            }
        }
        return res;
    }
};

//Method - 2
class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> res(n + 1);
        
        res[0] = 0;
        
        int t = 1;
        
        for(int i = 1; i <= n; i++){
            if((i & (i - 1)) == 0){
                t = i;
            }
            res[i] = res[i - t] + 1;
        }
        return res;
    }
};
