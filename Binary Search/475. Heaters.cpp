//Method - 1
class Solution {
public:
    #define ll long long
    bool heaterCoversAllHouses(ll radius, vector<int> &houses, vector<int> &heaters){
        
        ll ptr1 = 0, ptr2 = 0;
        
        while(ptr1 < houses.size() && ptr2 < heaters.size()){
            if(heaters[ptr2] >= houses[ptr1]){
                if((ll)heaters[ptr2] - radius <= (ll)houses[ptr1]){
                    ptr1++;
                }
                else{
                    return 0;
                }
            }
            else{
                if((ll)heaters[ptr2] + radius >= (ll)houses[ptr1]){
                    ptr1++;
                }
                else{
                    ptr2++;
                }
            }
        }
        if(ptr1 == houses.size()) return 1;
        return 0;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        ll lo = 0, hi = 1e9 + 7, ans;
        
        while(lo <= hi){
            ll mid = lo + (hi - lo)/2;
            if(heaterCoversAllHouses(mid, houses, heaters)){
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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        int n = heaters.size();
        
        int ans = 0;
        
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        
        for(int i = 0; i < houses.size(); i++){
            
            int lo = 0, hi = n - 1;
            int ind = -1, radius;
            
            while(lo <= hi){
                
                int mid = (lo + hi)/2;
                
                if(heaters[mid] <= houses[i]){
                    ind = mid;
                    lo = mid + 1;
                }
                else if(heaters[mid] > houses[i]){
                    hi = mid - 1;
                }
            }
            
            if(ind == -1){
                radius = abs(heaters[ind + 1] - houses[i]);
            }
            else if(ind == n - 1){
                radius = abs(heaters[ind] - houses[i]);
            }
            else{
                radius = min(abs(heaters[ind] - houses[i]), abs(heaters[ind+1] - houses[i]));   
            }
            ans = max(ans, radius);
        }
        return ans;
    }
};
