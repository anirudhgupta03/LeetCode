//Ref: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/discuss/1253874/C%2B%2B-Solution-sliding-window.-O(N)
//Method - 1
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

//Method - 2
class Solution {
public:
    int minFlips(string s) {
        
        int len = s.size();
        s += s;
        
        int count00 = 0, count01 = 0;
        int count10 = 0, count11 = 0;
        
        for(int i = 0; i < len; i++){
            if(i % 2 == 0){
                if(s[i] != '0') count00++;
                if(s[i] != '1') count11++;
            }
            else{
                if(s[i] != '0') count10++;
                if(s[i] != '1') count01++;
            }
        }
        
        int minCount = INT_MAX;
        minCount = min(minCount, min(count00 + count01, count10 + count11));
        
        for(int i = len; i < s.size(); i++){
            int tcount00, tcount01, tcount10, tcount11;
            tcount00 = count10;
            tcount01 = (s[i - len] == '1') ? count11 : count11 - 1;
            tcount10 = (s[i - len] == '1') ? count00 - 1 : count00;
            tcount11 = count01;
            
            if(s[i] == '1'){
                if(len % 2 == 0){
                    tcount10++;
                }
                else{
                    tcount00++;
                }
            }
            else{
                if(len % 2 == 0){
                    tcount01++;
                }
                else{
                    tcount11++;
                }
            }
            minCount = min(minCount, min(tcount00 + tcount01, tcount10 + tcount11));
            count00 = tcount00;
            count11 = tcount11;
            count10 = tcount10;
            count01 = tcount01;
        }
        return minCount;
    }
};
