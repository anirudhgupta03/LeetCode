//Ref: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/discuss/1211075/C%2B%2B-O(N)-with-explanation
class Solution {
public:
    int minSwaps(string s) {
        
        int ones = 0, zeros = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '0') zeros++;
            else ones++;
        }
        
        if(abs(zeros-ones) > 1){
            return -1;
        }
        
        string s1,s2;
        
        for(int i = 0; i < s.size(); i++){
            
            if(i % 2 == 0){
                s1.push_back('1');
                s2.push_back('0');
            }
            else{
                s1.push_back('0');
                s2.push_back('1');
            }
        }
        
        if(zeros == ones){
            
            int count1 = 0, count2 = 0;
            
            for(int i = 0; i < s.size(); i++){
                if(s[i] != s1[i]) count1++;
                if(s[i] != s2[i]) count2++;
            }
            
            return min(count1/2,count2/2);
        }
        
        if(zeros > ones){
            
            int count = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != s2[i]) count++;
            }
            
            return count/2;
        }
        
        int count = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != s1[i]) count++;
            }
            
        return count/2;
    }
};
