//Ref: https://www.youtube.com/watch?v=yKi8TIZcQoU
class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        int n = s.size();
        
        if(n % 2 != 0) return false;
        
        int extra = 0, balance = 0;
        
        for(int i = 0; i < n; i++){
            if(locked[i] == '0'){
                extra++;
            }
            else{
                balance += (s[i] == '(' ? 1 : -1);
                
                if(balance == -1){
                    balance = 0;
                    if(extra == 0) return false;
                    else           extra--;
                }
            }
        }
        
        extra = 0, balance = 0;
        
        for(int i = n - 1; i >= 0; i--){
            if(locked[i] == '0'){
                extra++;
            }
            else{
                balance += (s[i] == ')' ? 1 : -1);
                if(balance == -1){
                    balance = 0;
                    if(extra == 0) return false;
                    else extra--;
                }
            }
        }
        return true;
    }
};
