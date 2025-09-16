class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        long double res = 0;
        int ptr = 0;
        int sign = 1;

        while(ptr < len && s[ptr] == ' ') ptr++;
        
        if(ptr < len){
            if(s[ptr] == '-') sign = -1;
            if(s[ptr] == '-' || s[ptr] == '+') ptr++;
        }

        while(ptr < len){
            if(isdigit(s[ptr])){
                res = 10*res + (s[ptr] - '0');
                ptr++;
            }
            else{
                break;
            }
        }

        res = sign*res;
        if(res < INT_MIN) return INT_MIN;
        if(res > INT_MAX) return INT_MAX;
        return res;
    }
};
