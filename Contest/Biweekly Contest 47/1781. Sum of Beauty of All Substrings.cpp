class Solution {
public:
    int beautySum(string s) {
        
        int sum = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            int alpha[27] = {0};
            
            for(int j = i; j < s.size(); j++){
                
                alpha[s[j] - 96]++;
                
                int mostfreq = INT_MIN, leastfreq = INT_MAX;
                
                for(int k = 1; k <= 26; k++){
                    
                    if(mostfreq < alpha[k] && alpha[k] != 0){
                        mostfreq = alpha[k];
                    }
                    if(leastfreq > alpha[k] && alpha[k] != 0){
                        leastfreq = alpha[k];
                    }
                    
                }
                sum += mostfreq - leastfreq;
            }
        }
        
        return sum;
    }
};
