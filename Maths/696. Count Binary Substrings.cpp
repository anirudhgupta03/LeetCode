class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int pcount = 0;
        int tcount = 0;
        int currcount = 0;
        
        int i = 0;
        
        while(i < s.size()){
            
            currcount = 0;
            
            if(s[i] == '0'){
                while(i < s.size() && s[i] == '0'){
                    i++;
                    currcount++;
                }
                tcount += min(pcount, currcount);
                pcount = currcount;
            }
            else{
                while(i < s.size() && s[i] == '1'){
                    i++;
                    currcount++;
                }
                tcount += min(pcount, currcount);
                pcount = currcount;
            }
        }
        return tcount;
    }
};
