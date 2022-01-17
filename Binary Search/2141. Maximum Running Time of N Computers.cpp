//Ref: https://www.youtube.com/watch?v=Jc5aAtzDqmg
class Solution {
public:
    #define ll long long
    bool isPossible(ll mid, vector<int> &batteries, ll n){
        
        ll currBatSum = 0;
        ll targetBatSum = n*mid;
        
        for(int bat: batteries){
            if(bat < mid){
                currBatSum += bat;
            }
            else{
                currBatSum += mid;
            }
            
            if(currBatSum >= targetBatSum){
                return true;
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        
        ll totalSum = 0;
        ll lo = INT_MAX;
        
        for(int bat: batteries){
            totalSum += bat;
            lo = min((ll)bat, lo);
        }
        
        ll hi = (totalSum/n);
        ll ans = -1;
        
        while(lo <= hi){
            
            ll mid = lo + (hi - lo)/2;
            
            if(isPossible(mid, batteries, n)){
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
