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
