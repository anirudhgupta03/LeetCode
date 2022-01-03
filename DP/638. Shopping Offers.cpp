class Solution {
public:
    #define pivi pair<int,vector<int>> 
    int solve(int sum, vector<int> &price, vector<vector<int>> &special, vector<int> &needs, map<pivi,int> &dp){
        
        if(sum == 0){
            return 0;
        }
        
        if(dp.find({sum,needs}) != dp.end()){
            return dp[{sum,needs}];
        }
        
        int mincost = INT_MAX;
        
        for(int i = 0; i < needs.size(); i++){
            if(needs[i] != 0){
                int temp = needs[i];
                needs[i] = 0;
                mincost = min(mincost, solve(sum - temp, price, special, needs, dp) + temp*price[i]);
                needs[i] = temp;
            }
        }
        
        for(int i = 0; i < special.size(); i++){
            bool flag = true;
            for(int j = 0; j < needs.size(); j++){
                if(special[i][j] > needs[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                int tsum = 0;
                for(int j = 0; j < special[i].size() - 1; j++){
                    tsum += special[i][j];
                    needs[j] -= special[i][j];
                }
                mincost = min(mincost, solve(sum - tsum, price, special, needs, dp) + special[i][special[i].size() - 1]);
                for(int j = 0; j < special[i].size() - 1; j++){
                    needs[j] += special[i][j];
                }
            }
        }
        return dp[{sum,needs}] = mincost;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        int cost = 0, mincost = INT_MAX;
        
        int sum = 0;
        
        for(int i = 0; i < needs.size(); i++){
            sum += needs[i];
        }
        
        map<pivi,int> dp;
        
        return solve(sum, price, special, needs, dp);
    }
};
