//Method - 1
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        for(int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }
        
        int ans = 0;
        
        for(int p = 0; p < n; p++){
            
            vector<int> v;
            for(int j = p; j < p + n; j++){
                v.push_back(nums[j]);
            }
            vector<pair<int,int>> dp(n);
        
            dp[0] = {0, v[0]};

            if(v[1] >= v[0]){
                dp[1] = {1, v[1]};
            }
            else{
                dp[1] = {0, v[0]};
            }

            for(int i = 2; i < n - 1; i++){
                if(v[i] + dp[i - 2].second > dp[i - 1].second){
                    dp[i] = {dp[i - 2].first, v[i] + dp[i - 2].second};
                }
                else if(v[i] + dp[i - 2].second == dp[i - 1].second){
                    if(dp[i - 1].first || dp[i - 2].first){
                        dp[i] = {1, dp[i - 1].second};
                    }
                    else{
                        dp[i] = {0, dp[i - 1].second};
                    }
                }
                else{
                    dp[i] = dp[i - 1];
                }
            }

            dp[n - 1] = dp[n - 2];

            if(dp[n - 3].second + v[n - 1] > dp[n - 1].second && dp[n - 3].first == 1){
                dp[n - 1] = {1, dp[n - 3].second + v[n - 1]};
            }
            
            ans = max({ans, nums[n - 1], dp[n - 1].second});
        }
        return ans;
    }
};

//Method - 2
//Nice Question
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0],nums[1]);
        }
        
        int maxrob = 0;
        
        vector<pair<int,int>> dp(n,{-1,-1});
        
        dp[0] = {nums[0],0};
        if(nums[0] > nums[1]){
            dp[1] = {max(nums[0],nums[1]),0};
        }
        else{
            dp[1] = {max(nums[0],nums[1]),1};
        }
        
        for(int i = 2; i < n - 1; i++){
            if(dp[i-2].first + nums[i] > dp[i-1].first){        
                dp[i] = {dp[i-2].first + nums[i],dp[i-2].second};
            }
            else if(dp[i-2].first + nums[i] == dp[i-1].first){
                if(dp[i-1].second == 1 || dp[i-2].second == 1){
                    dp[i] = {dp[i-2].first + nums[i],1};
                }
                else{
                    dp[i] = {dp[i-2].first + nums[i],0};
                }
            }
            else{
                dp[i] = {dp[i-1].first,dp[i-1].second};
            }
        }
        
        dp[n-1] = {dp[n-2].first, dp[n-2].second};
        
        if(dp[n-3].second == 0){
            if(dp[n-3].first > dp[n-1].first){
                dp[n-1].first = dp[n-3].first;
            }
        }
        else{
            if(dp[n-3].first + nums[n-1] > dp[n-1].first){
                dp[n-1].first = dp[n-3].first + nums[n-1]; 
            }
        }
        if(nums[n-1] > dp[n-1].first) dp[n-1].first = nums[n-1];
       
        int res = dp[n-1].first;
        
        for(int i = 0; i < n; i++){
            dp[i] = {-1,-1};
        }
        
        dp[n-1] = {nums[n-1],0};
        if(nums[n-1] > nums[n-2]){
            dp[n-2] = {max(nums[n-1],nums[n-2]),0};
        }
        else{
            dp[n-2] = {max(nums[n-1],nums[n-2]),1};
        }
        
        for(int i = n-3; i >= 1; i--){
            
            if(dp[i+2].first + nums[i] > dp[i+1].first){        
                dp[i] = {dp[i+2].first + nums[i],dp[i+2].second};
            }
            else if(dp[i+2].first + nums[i] == dp[i+1].first){
                if(dp[i+1].second == 1 || dp[i+2].second == 1){
                    dp[i] = {dp[i+2].first + nums[i],1};
                }
                else{
                    dp[i] = {dp[i+2].first + nums[i],0};
                }
            }
            else{
                dp[i] = {dp[i+1].first,dp[i+1].second};
            }
        }
        
        dp[0] = {dp[1].first, dp[1].second};
        
        if(dp[2].second == 0){
            if(dp[2].first > dp[0].first){
                dp[0].first = dp[2].first;
            }
        }
        else{
            if(dp[2].first + nums[0] > dp[0].first){
                dp[0].first = dp[2].first + nums[0]; 
            }
        }
        if(nums[0] > dp[0].first) dp[0].first = nums[0];
        
        res = max(res, dp[0].first);
        return res;
    }
};

//Method - 3
//Optimal Method
//Ref: https://www.youtube.com/watch?v=3WaxQMELSkw
class Solution {
public:
    int solve(int lo, int hi, vector<int> &nums){
        
        int val1 = nums[lo];
        int val2 = max(nums[lo], nums[lo + 1]);
        
        for(int i = lo + 2; i <= hi; i++){
            int val3 = max(val1 + nums[i], val2);
            val1 = val2;
            val2 = val3;
        }
        return val2;
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        int ans1 = solve(0, n - 2, nums);
        int ans2 = solve(1, n - 1, nums);
        return max(ans1, ans2);
    }
};
