//Ref1: https://www.youtube.com/watch?v=MjpAAE3-hYg
//Ref2: https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/discuss/1119755/Intuition-explained-or-Binary-search-or-Java-or-Heavily-commented-or-Easy-to-understand
//Method - 1
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

//Method - 2
class Solution {
public:
    #define ll long long
    bool isValid(ll maxValue, ll n, ll index, ll maxSum){
        
        ll lsum = 0, rsum = 0;
        
        if(maxValue - 1 <= index){
            lsum += (maxValue*(maxValue + 1))/2;
            lsum += index + 1 - maxValue;
        }
        else{
            ll temp = maxValue - index - 1;
            lsum += (maxValue*(maxValue + 1))/2 - (temp*(temp + 1))/2;
        }
        
        if(n - index >= maxValue){
            rsum += (maxValue*(maxValue + 1))/2;
            rsum += n - index - maxValue;
        }
        else{
            ll temp = maxValue - (n - index);
            rsum += (maxValue*(maxValue + 1))/2 - (temp*(temp + 1))/2;
        }
        
        return lsum + rsum - maxValue <= maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        
        ll lo = 1, hi = maxSum, ans;
        
        while(lo <= hi){
            
            ll mid = lo + (hi - lo)/2;
      
            if(isValid(mid, n, index, maxSum)){
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
