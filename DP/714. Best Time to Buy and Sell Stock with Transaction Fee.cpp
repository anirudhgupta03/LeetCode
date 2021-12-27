//Ref: https://www.youtube.com/watch?v=pTQB9wbIpfU
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int bsp = -prices[0], ssp = 0;
        
        for(int i = 1; i < prices.size(); i++){
            
            int nbsp = 0, nssp = 0;
            
            nbsp = max(bsp, ssp - prices[i]);
            nssp = max(ssp, bsp + prices[i] - fee);
            
            bsp = nbsp;
            ssp = nssp;
        }
        
        return ssp;
    }
};
