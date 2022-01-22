class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        int n = cost.size();
        
        if(n == 1){
            return cost[0];
        }
        if(n == 2){
            return cost[0] + cost[1];
        }
        
        sort(cost.begin(),cost.end());

        int ind = n - 1, sum = 0;
        
        while(ind >= 0){
            if(ind >= 1) sum += cost[ind] + cost[ind - 1];
            else sum += cost[ind];
            
            ind -= 3;
        }
        return sum;
    }
};
