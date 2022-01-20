//Ref: https://leetcode.com/problems/monotone-increasing-digits/discuss/150752/Clean-Code
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        
        string s = to_string(n);
        
        int end = s.size() - 1;
        
        for(int i = s.size() - 1; i > 0; i--){
            if(s[i] < s[i - 1]){
                end = i - 1;
                s[i-1]--;
            }
        }
        
        for(int i = end + 1; i < s.size(); i++){
            s[i] = '9';
        }
        return stoi(s);
    }
};
