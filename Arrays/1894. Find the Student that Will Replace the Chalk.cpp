class Solution {
public:
    #define ll long long
    int chalkReplacer(vector<int>& chalk, int k) {
        
        ll sum = 0;
        
        for(auto x: chalk){
            sum += x;
        }
        
        k %= sum;
        
        for(int i = 0; i < chalk.size(); i++){
            
            k -= chalk[i];
            
            if(k < 0){
                return i;
            }
        }
        return 0;
    }
};
