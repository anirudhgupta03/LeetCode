class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        int val1 = 0, val2 = 0;
        
        for(int i = 2; i <= n; i++){
            int val3 = min(val2 + cost[i - 1], val1 + cost[i - 2]);
            val1 = val2;
            val2 = val3;
        }
        return val2;
    }
};
