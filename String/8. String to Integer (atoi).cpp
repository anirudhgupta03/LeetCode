class Solution {
public:
    #define ll long long
    int myAtoi(string s) {
        
        int i = 0;
        
        while(i < s.size() && s[i] == ' '){
            i++;
        }
        
        if(i == s.size()){
            return 0;
        }
        bool flag1 = 0, flag2 = 0;
        int sign = 1;
        
        string ans;
        
        while(i < s.size()){
            
            if(s[i] == '-' || s[i] == '+'){
                if(flag1 || flag2){
                    break;
                }
                if(s[i] == '-'){
                    sign = -1;
                }
                flag1 = true;
            }
            else if(isdigit(s[i])){
                flag2 = true;
                ans.push_back(s[i]);
            }
            else{
                break;
            }
            
            i++;
        }
        
        ll val = 0;
        
        for(int i = 0; i < ans.size(); i++){
            
            val = 10*val + ans[i]-'0';
            
            if(sign == 1){
                if(val > INT_MAX){
                    return INT_MAX;
                }
            }
            if(sign == -1){
                if(-1*val < INT_MIN){
                    return INT_MIN;
                }
            }
        }
        
        return sign*val;
    }
};
