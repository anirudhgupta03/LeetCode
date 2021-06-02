class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        
        int n = digits.size();
        int d[10] = {0};
        
        int rem1[6] = {1,4,7,2,5,8};
        int rem2[6] = {2,5,8,1,4,7};
        
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            d[digits[i]]++;
            sum += digits[i];
        }
        
        while(sum % 3 != 0){
            
            for(int i = 0; i < 6; i++){
                if(sum % 3 == 1 && d[rem1[i]]){
                    sum -= rem1[i];
                    d[rem1[i]]--;
                    break;
                }
                else if(sum % 3 == 2 && d[rem2[i]]){
                    sum -= rem2[i];
                    d[rem2[i]]--;
                    break;
                }
            }
        }
        
        string ans = "";
        
        for(int i = 9; i >= 0; i--){
            for(int j = 1; j <= d[i]; j++){
                ans += to_string(i);
            }
        }
        
        if(ans[0] == '0'){
            return "0";
        }
        return ans;
    }
};
