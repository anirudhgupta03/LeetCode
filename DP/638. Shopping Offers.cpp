class Solution {
public:
    map<vector<int>,int> dp;
    int solve(int count, vector<int> &price, vector<vector<int>> &special, vector<int> &needs){
        
        bool flag = true;
        
        if(count == 0){
            return 0;
        }
        
        if(dp.find(needs) != dp.end()){
            return dp[needs];
        }
        int minPrice = INT_MAX;
        
        for(int i = 0; i < price.size(); i++){
            if(needs[i] != 0){
                int temp = needs[i];
                needs[i] = 0;
                minPrice = min(minPrice, solve(count - temp, price, special, needs) + temp*price[i]);
                needs[i] = temp;
            }
        }
        
        for(int i = 0; i < special.size(); i++){
            bool flag = true;
            for(int j = 0; j < needs.size(); j++){
                if(needs[j] < special[i][j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                int t = 0;
                for(int j = 0; j < needs.size(); j++){
                    needs[j] -= special[i][j];
                    t += special[i][j];
                }
                minPrice = min(minPrice, solve(count - t, price, special, needs) + special[i][needs.size()]);
                for(int j = 0; j < needs.size(); j++){
                    needs[j] += special[i][j];
                }
            }
        }
        return dp[needs] = minPrice;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        dp.clear();
        int count = 0;
        for(int x: needs){
            count += x;
        }
        return solve(count, price, special, needs);
    }
};
