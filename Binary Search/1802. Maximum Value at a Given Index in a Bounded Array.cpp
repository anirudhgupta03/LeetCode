//Ref1: https://www.youtube.com/watch?v=MjpAAE3-hYg
//Ref2: https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/discuss/1119755/Intuition-explained-or-Binary-search-or-Java-or-Heavily-commented-or-Easy-to-understand
class Solution {
public:
    #define ll long long
    int maxValue(int n, int index, int maxSum) {
        
        ll lspace = index, rspace = n - index - 1;
        
        ll lo = 1, hi = maxSum;
        
        ll res = 0;
        
        while(lo <= hi){
            
            ll mid = (lo + hi)/2;
            
            ll sum = 0;
            
            if(mid - rspace >= 1){
                
                ll n1 = mid - rspace - 1;
                ll n2 = mid;
                sum += (n2*(n2+1))/2 - (n1*(n1+1))/2;
            }
            else{
                
                ll n1 = rspace + 1 - mid;
                ll n2 = mid;
                sum += (n2*(n2+1))/2 + n1;
            }
            
            if(mid - lspace >= 1){
                
                ll n1 = mid - lspace - 1;
                ll n2 = mid - 1;
                sum += (n2*(n2+1))/2 - (n1*(n1+1))/2;
            }
            else{
                
                ll n1 = lspace + 1 - mid;
                ll n2 = mid - 1;
                sum += (n2*(n2+1))/2 + n1;
            }
          
            if(sum <= maxSum){
                res = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        
        return res;
    }
};
