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
