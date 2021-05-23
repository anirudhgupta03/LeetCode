class Solution {
public:
    int daysTaken(int cap, vector<int> &weights){
        
        int count = 1;
        
        int sum = 0;
        
        for(int i = 0; i < weights.size(); i++){
            
            sum += weights[i];
            if(sum > cap){
                count++;
                sum = weights[i];
            }
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int lo = INT_MIN, hi = 0;
        
        for(int i = 0; i < weights.size(); i++){
            hi += weights[i];
            lo = max(lo,weights[i]);
        }
        
        int ans;
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(daysTaken(mid,weights) <= days){
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
