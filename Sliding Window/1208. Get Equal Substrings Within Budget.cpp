class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int lo = 0, hi = 0;
        
        int maxlen = 0, cost = 0;
        
        while(hi < s.size()){
            
            if(s[hi] == t[hi]){
                hi++;
            }
            else{
                cost += abs(s[hi] - t[hi]);
                if(cost <= maxCost){
                    hi++;
                }
                else{
                    while(lo <= hi && cost > maxCost){
                        maxlen = max(maxlen, hi - lo);
                        
                        if(s[lo] == t[lo]){
                            lo++;
                        }
                        else{
                            cost -= abs(s[lo]-t[lo]);
                            lo++;
                        }
                    }
                    hi++;
                }
            }
        }
        maxlen = max(maxlen, hi - lo);
        return maxlen;
    }
};
