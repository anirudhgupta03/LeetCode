//Ref: https://www.youtube.com/watch?v=qyfekrNni90&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=12
class Solution {
public:
    #define ll long long
    int timeTaken(int speed, vector<int>& piles){
        
        int t = 0;
        for(int i = 0; i < piles.size(); i++){
            t += ceil((double)piles[i]/speed);
        }
        return t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int lo = 1, hi = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            hi = max(hi,piles[i]);
        }
        
        int ans;
        while(lo <=  hi){
            int mid = (lo + hi)/2;
            if(timeTaken(mid,piles) <= h){
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
