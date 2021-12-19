class Solution {
public:
    #define ll long long
    long long getDescentPeriods(vector<int>& prices) {
        
        int n = prices.size();
        
        if(n == 1) return 1;
        
        ll count = 0;
        
        int lo = 0, hi = 1;
        
        while(hi < n){
            
            int diff = prices[lo] - prices[hi];
            
            if(diff != 1){
                count++;
                lo++;
                hi++;
                if(hi == n){
                    count++;
                }
            }
            
            else{
                int tdiff = prices[lo] - prices[hi];
            
                ll cnt = 1;

                while(diff == tdiff && hi < n - 1){
                    hi++;
                    cnt++;
                    tdiff = prices[hi-1] - prices[hi];
                }
                bool flag = false;
                
                if(hi == n - 1 && tdiff == 1){
                    flag = true;
                    cnt++;
                }
                count +=  ((cnt)*(cnt + 1))/(ll)2;
                
                lo = hi;
                hi = lo + 1;
                if(!flag && hi == n){
                    count++;
                }
            }
        }
        return count;
    }
};
