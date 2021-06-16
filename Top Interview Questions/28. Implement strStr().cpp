//KMP Algorithm
//Time Complexity - O(N)
//Space Complexity - O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.size() == 0){
            return 0;
        }
        
        if(needle.size() > haystack.size()){
            return -1;
        }
        
        int n = needle.size();
        
        vector<int> lps(n,0);
        
        int l = 0, r = 1;
        
        while(r < n){
            
            if(needle[r] == needle[l]){
                lps[r] = l + 1;
                l++;
                r++;
            }
            else if(l == 0 && needle[r] != needle[l]){
                r++;
            }
            else if(l != 0 && needle[r] != needle[l]){
                l = lps[l-1];
            }
        }
        
        int j = -1, i = 0;
        
        while(i < haystack.size()){
            
            if(haystack[i] == needle[j+1]){
                i++;
                j++;
            }
            else if(j == -1 && haystack[i] != needle[j+1]){
                i++;
            }
            else{
                j = lps[j] - 1;
            }
        
            if(j == n - 1){
                return i - n;
            }
        }
        return -1;
    }
};
