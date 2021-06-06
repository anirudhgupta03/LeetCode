//Ref: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/discuss/1253874/C%2B%2B-Solution-sliding-window.-O(N)
class Solution {
public:
    int minFlips(string s) {
        
        int n = s.size();
        s += s;
        string s1,s2;
        
        for(int i = 0; i < s.size(); i++){
            
            if(i % 2 == 0){
                s1.push_back('0');
                s2.push_back('1');
            }
            else{
                s1.push_back('1');
                s2.push_back('0');
            }
        }
        
        int i = 0, op1 = 0, op2 = 0, ans = INT_MAX;
        
        while(i < s.size()){
            
            if(s1[i] != s[i]){
                op1++;
            }
            if(s2[i] != s[i]){
                op2++;
            }
            
            if(i >= n){
                if(s1[i-n] != s[i-n]){
                    op1--;
                }
                if(s2[i-n] != s[i-n]){
                    op2--;
                }
            }
            if(i >= n -1){
                ans = min(ans,min(op1,op2));
            }
            i++;
        } 
        return ans;
    }
};
