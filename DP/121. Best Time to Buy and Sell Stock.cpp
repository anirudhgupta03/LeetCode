//Ref: https://www.youtube.com/watch?v=excAOvwF_Wk&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=10
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minEle = prices[0];
        
        int maxProfit = 0;
        
        for(int i = 1; i < prices.size(); i++){
            
            if(prices[i] < minEle){
                minEle = prices[i];
            }
            else{
                maxProfit = max(maxProfit, prices[i] - minEle);
            }
        }
        
        return maxProfit;
    }
};
