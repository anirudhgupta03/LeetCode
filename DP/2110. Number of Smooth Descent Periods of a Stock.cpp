class Solution {
public:
    #define ll long long
    long long getDescentPeriods(vector<int>& prices) {
        
        ll count = 1, ans = 0;
        
        for(int i = 1; i < prices.size(); i++){
            if(prices[i - 1] == prices[i] + 1){
                count++;
            }
            else{
                ans += (count*(count + 1))/2;
                count = 1;
            }
        }
        ans += (count*(count + 1))/2;
        return ans;
    }
};
