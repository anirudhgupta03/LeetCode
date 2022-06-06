//Ref: https://www.youtube.com/watch?v=XjLT4TaXsgw
//Method - 1
class Solution {
public:
    #define ll long long
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1 || n == 2){
            return 0;
        }
        vector<unordered_map<ll,int>> dp(n);
        
        int count = 0;
        
        unordered_map<ll,int> mp;
        
        mp[(ll)((ll)nums[1] - (ll)nums[0])] = 1;
        dp[1] = mp;
        
        for(int i = 2; i < n; i++){
            //unordered_map<ll,int> mp2;
            for(int j = 0; j < i; j++){
                
                ll temp = (ll)((ll)nums[i]-(ll)nums[j]);
                
                if(temp < INT_MIN || temp > INT_MAX){
                    continue;
                }
                if(dp[j][temp] != 0){
                    count += dp[j][temp];
                    dp[i][temp] += dp[j][temp] + 1;
                }
                else{
                    if(dp[i][temp] != 0){
                        dp[i][temp]++;
                    }
                    else{
                        dp[i][temp] = 1;
                    }
                }
            }
        }
        return count;
    }
};

//Method - 2
class Solution {
public:
    #define ll long long
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n <= 2) return 0;
        
        vector<unordered_map<ll,ll>> dp(n);
        
        ll count = 0;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                
                ll diff = (ll)nums[i] - (ll)nums[j];
                
                if(dp[j].find(diff) != dp[j].end()){
                    count += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
                
                dp[i][diff]++;
            }
        }
        return count;
    }
};
