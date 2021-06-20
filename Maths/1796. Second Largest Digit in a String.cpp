class Solution {
public:
    int secondHighest(string s) {
        
        int l = INT_MIN, sl = INT_MIN;
        
        for(int i = 0; i < s.size(); i++){
            
            if(isdigit(s[i])){
                
                int n = s[i] - '0';
                if(n > l){
                    sl = l;
                    l = n;
                }
                else if(n!= l && n > sl){
                    sl = n;
                }
            }
        }
        
        if(sl == INT_MIN){
            return -1;
        }
        return sl;
    }
};
