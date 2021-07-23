class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        int arr1[n], arr2[n];
        
        int minEle = INT_MAX, maxprofit = 0;
        
        for(int i = 0; i < n; i++){
            
            if(prices[i] < minEle){
                minEle = prices[i];
            }
            
            maxprofit = max(maxprofit, prices[i] - minEle);
            
            arr1[i] = maxprofit;
        }
        
        maxprofit = 0;
        int maxEle = INT_MIN;
        
        for(int i = n - 1; i >= 0; i--){
            
            if(prices[i] > maxEle){
                maxEle = prices[i];
            }
            
            maxprofit = max(maxprofit, maxEle - prices[i]);
            
            arr2[i] = maxprofit;
        }
        
        maxprofit = 0;
        
        for(int i = 0; i < n; i++){
            maxprofit = max(maxprofit, arr1[i] + arr2[i]);
        }
        
        return maxprofit;
    }
};
