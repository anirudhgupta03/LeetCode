//Ref: https://leetcode.com/problems/maximum-number-of-removable-characters/discuss/1268477/JAVA-Binary-Search-with-Detailed-Explanation!
class Solution {
public:
    bool isSubsequence(string s, string p){
        
        int i = 0, j = 0;
        
        while(i < s.size() && j < p.size()){
            
            if(s[i] != p[j]){
                i++;
            }
            else if(s[i] == p[j]){
                i++;
                j++;
            }
        }
        
        if(j == p.size()){
            return true;
        }
        return false;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        int lo = 0, hi = removable.size() - 1;
        
        int maxRem = 0;
        
        string temp = s;
        
        while(lo <= hi){
            
            int mid = (lo+hi)/2;
            
            for(int i = 0; i <= mid; i++){
                temp[removable[i]] = '/';
            }
            
            if(isSubsequence(temp,p)){
                maxRem = max(maxRem,mid + 1);
                lo = mid + 1;
            }
            else{
                for(int i = 0; i <= mid; i++){
                    temp[removable[i]] = s[removable[i]];
                }
                hi = mid - 1;
            }
        }
        return maxRem;
    }
};
