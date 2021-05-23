//Binary Search
//Ref: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/discuss/1224643/Java-binary-search-explained
class Solution {
public:
    
    double timeTaken(int speed, vector<int> &dist){
        
        double total = 0;
        // we take ceil of all train times, leaving last time
        // because need need to wait after all trains leaving the last one
        // so here ceil will round off the time to the next integer, (i.e 1.5 -> 2)
        for(int i = 0; i < dist.size(); i++){
            // adding last train time in decimal values
            if(i == dist.size() - 1){
                total += (double)dist[i]/speed;
            }
            else{
                total += ceil((double)dist[i]/speed); // adding train time after rounding off to next int
            }
        }
        
        return total;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // min speed can be 1, and max can be 10^7
        int lo = 1, hi = 1e7;
        
        int ans = -1;
        
        while(lo <= hi){
            
            int mid = (lo+hi)/2;
            // if time taken <= hour, then this speed can be answer
            // but we will try for less speed, maybe less is our answer
            if(timeTaken(mid,dist) <= hour){
                ans = mid;
                hi = mid - 1;
            }
            // speed was too less, so the time taken was much more
            // hence we need more speed so increment the lower bound
            else{
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
