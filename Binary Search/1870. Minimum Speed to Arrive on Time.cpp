class Solution {
public:
    
    double timeTaken(int speed, vector<int> &dist){
        
        double total = 0;
        
        for(int i = 0; i < dist.size(); i++){
            
            if(i == dist.size() - 1){
                total += (double)dist[i]/speed;
            }
            else{
                total += ceil((double)dist[i]/speed);
            }
        }
        
        return total;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int lo = 1, hi = 1e7;
        
        int ans = -1;
        
        while(lo <= hi){
            
            int mid = (lo+hi)/2;
            
            if(timeTaken(mid,dist) <= hour){
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
