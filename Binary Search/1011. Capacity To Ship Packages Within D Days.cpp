//Ref: https://www.youtube.com/watch?v=MG-Ac4TAvTY&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=15
class Solution {
public:
    bool isPossibleToShipPackagesWithinDDays(int shipCapacity, vector<int>& weights, int days){
        int daysTaken = 1, cap = 0;
        for(int &weight: weights){
            cap += weight;
            if(cap > shipCapacity){
                daysTaken++;
                cap = weight;
            }
        }
        return daysTaken <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo = INT_MIN, hi = 0;
        for(int &weight: weights){
            lo = max(lo, weight);
            hi += weight;
        }
        int ans;
        while(lo <= hi){
            int shipCapacity = lo + (hi - lo)/2;
            if(isPossibleToShipPackagesWithinDDays(shipCapacity, weights, days)){
                ans = shipCapacity;
                hi = shipCapacity - 1;
            }
            else{
                lo = shipCapacity + 1;
            }
        }
        return ans;
    }
};
