class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        
        int rem1[6] = {1,4,7,2,5,8};
        int rem2[6] = {2,5,8,1,4,7};
        
        int d[10];
        memset(d,0,sizeof(d));
        
        int sum = 0;
        
        for(auto &x: digits){
            d[x]++;
            sum += x;
        }
        
        while(sum % 3 != 0){
            if(sum % 3 == 1){
                for(int i = 0; i < 6; i++){
                    if(d[rem1[i]]){
                        d[rem1[i]]--;
                        sum -= rem1[i];
                        break;
                    }
                }
            }
            else{
                for(int i = 0; i < 6; i++){
                    if(d[rem2[i]]){
                        d[rem2[i]]--;
                        sum -= rem2[i];
                        break;
                    }
                }
            }
        }
        
        string res;
        for(int i = 9; i >= 0; i--){
            for(int j = 1; j <= d[i]; j++){
                res += to_string(i);
            }
        }
        if(res[0] == '0') return "0";
        return res;
    }
};
