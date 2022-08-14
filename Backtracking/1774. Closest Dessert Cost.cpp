class Solution {
public:
    void solve(int ind, int price, int &tsum, int &minDiff, vector<int> &toppingCosts, int target){
        
        if(abs(price - target) < minDiff){
            minDiff = abs(price - target);
            tsum = price;
        }
        if(abs(price - target) == minDiff && price < tsum){
            tsum = price;
        }
        if(ind == toppingCosts.size()){
            return;
        } 
        
        solve(ind + 1, price, tsum, minDiff, toppingCosts, target);
        solve(ind + 1, price + toppingCosts[ind], tsum, minDiff, toppingCosts, target);
        solve(ind + 1, price + 2*toppingCosts[ind], tsum, minDiff, toppingCosts, target);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        
        int n = baseCosts.size();
        int tsum = INT_MAX, minDiff = INT_MAX;
      
        for(int i = 0; i < baseCosts.size(); i++){
            solve(0, baseCosts[i], tsum, minDiff, toppingCosts, target);
        }
        return tsum;
    }
};
