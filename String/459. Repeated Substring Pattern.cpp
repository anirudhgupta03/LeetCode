//Ref: https://www.youtube.com/watch?v=p92_kEjyJAo
//Time Complexity - O(N)
//Space Complexity - O(N)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n = s.size();
        
        vector<int> lps(n,0);
        
        int l = 0, r = 1;
        
        while(r < n){
            
            if(s[l] == s[r]){
                lps[r] = l + 1;
                l++;
                r++;
            }
            else if(l == 0){
                r++;
            }
            else{
                l = lps[l-1];
            }
        }
        
        int len = lps[n-1];
        
        if(len != 0 && (len%(n-len)) == 0){
            return true;
        }
        return false;
    }
};
