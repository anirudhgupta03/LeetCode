class Solution {
public:
    bool checkZeroOnes(string s) {
        
        
        int ones = 0, zeros = 0;
        
        int i = 0;
        
        while(i < s.size()){
            
            if(s[i] == '1'){
                int count = 0;
                while(s[i] == '1' && i < s.size()){
                    count++;
                    i++;
                }
                
                ones = max(count,ones);
            }
            else{
                int count = 0;
                while(s[i] == '0' && i < s.size()){
                    count++;
                    i++;
                }
                zeros = max(count,zeros);
            }
        }
        
        if(ones > zeros){
            return true;
        }
        return false;
    }
};
