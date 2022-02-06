class Solution {
public:
    #define ll long long
    long long smallestNumber(long long num) {
        
        if(num == 0){
            return 0;
        }
        
        vector<int> digits;
        
        ll temp = abs(num);
        int zeros = 0;
        while(temp){
            digits.push_back(temp % 10);
            if(temp % 10 == 0) zeros++;
            temp /= 10;
        }
        
        sort(digits.begin(), digits.end());
        
        if(num < 0){
            ll ans = 0;
            for(int i = digits.size() - 1; i >= 0; i--){
                ans = 10*ans + digits[i];
            }
            return -1*ans;
        }
        else{
            ll ans = 0;
            bool flag = false;
            for(int i = 0; i < digits.size(); i++){
                if(digits[i] == 0) continue;
                else{
                    if(!flag){
                      ans = 10*ans + digits[i];
                      while(zeros--){
                          ans = 10*ans;
                      }
                      flag = true;
                    }
                    else{
                        ans = 10*ans + digits[i];
                    }
                }
            }
            return ans;
        }
    }
};
