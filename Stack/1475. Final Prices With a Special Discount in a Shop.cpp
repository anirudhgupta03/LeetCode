class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<int> ans;
        ans.push_back(prices[n-1]);
        
        stack<int> s;
        s.push(prices[n-1]);
        
        for(int i = n - 2; i >= 0; i--){
            
            if(s.top() <= prices[i]){
                ans.push_back(prices[i] - s.top());
            }
            else{
                
                while(!s.empty() && s.top() > prices[i]){
                    s.pop();
                }
                
                if(s.empty()){
                    ans.push_back(prices[i]);
                }
                else{
                    ans.push_back(prices[i] - s.top());
                }
            }
            s.push(prices[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
