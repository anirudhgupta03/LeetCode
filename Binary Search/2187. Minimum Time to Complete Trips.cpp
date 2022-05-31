//Method - 1
class Solution {
public:
    #define ll long long
    bool isValid(ll t, vector<int> &time, int total){
        
        ll count = 0;
        for(int i = 0; i < time.size(); i++){
            count += (t/time[i]);
        }
        if(count >= total){
            return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        ll sum = 0;
        
        for(int i = 0; i < time.size(); i++){
            sum += time[i];
        }
        
        ll lo = 1, hi = sum * totalTrips;
        ll ans;
        while(lo <= hi){
            
            ll mid = (lo + hi)/2;
            
            if(isValid(mid, time, totalTrips)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};

//Method - 2
class Solution {
public:
    #define ll long long
    bool isPossibleToComplete(ll t, vector<int> &time, ll totalTrips){
        ll count = 0;
        for(int i = 0; i < time.size(); i++){
            count += t/time[i];
            if(count >= totalTrips) return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        ll lo = 1, hi = (ll)*min_element(time.begin(), time.end())*totalTrips;
        
        ll ans;
        
        while(lo <= hi){
            
            ll mid = lo + (hi - lo)/2;
            
            if(isPossibleToComplete(mid, time, totalTrips)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};
