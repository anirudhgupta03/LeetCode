//Method - 1
class Solution {
public:
    bool canBeChanged(int len, string s, string t, int maxCost){
        
        int i = 0, cost = 0;
        
        for(; i < len - 1; i++){
            cost += abs(s[i] - t[i]);
        }
        
        for(; i < s.size(); i++){
            cost += abs(s[i] - t[i]);
            if(cost <= maxCost) return true;
            cost -= abs(s[i - len + 1] - t[i - len + 1]);
        }
        
        return false;
    }
    int equalSubstring(string s, string t, int maxCost) {
        
        int lo = 1, hi = s.size(), ans = 0;
        
        while(lo <= hi){
            
            int mid = lo + (hi - lo)/2;
            
            if(canBeChanged(mid, s, t, maxCost)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};

//Method - 2
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
