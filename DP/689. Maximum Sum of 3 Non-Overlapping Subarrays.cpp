//Ref: https://www.youtube.com/watch?v=mXeT7-oZeQQ
//Method - 1
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> prefix(n + 1, 0);
        
        for(int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + nums[i-1];
        
        vector<pair<int,int>> dp1(n);
        
        int sum1 = 0;
        
        for(int i = 0; i < k; i++) sum1 += nums[i];
        
        dp1[k-1] = {0,sum1};
        
        for(int i = k; i < n; i++){
            if(dp1[i-1].second >= prefix[i + 1] - prefix[i - k + 1]){
                dp1[i] = dp1[i-1];
            }
            else{
                dp1[i] = {i - k + 1 ,prefix[i + 1] - prefix[i - k + 1]};
            }
            
        }
       
        vector<pair<int,int>> dp2(n);
        
        int sum2 = 0;
        
        for(int i = n - 1; i >= n - k; i--) sum2 += nums[i];
        
        dp2[n-k] = {n-k, sum2};
        
        for(int i = n - k - 1; i >= 0; i--){
            if(dp2[i+1].second > prefix[i + k] - prefix[i]){
                dp2[i] = dp2[i+1];
            }
            else{
                dp2[i] = {i, prefix[i + k] - prefix[i]};
            }
            
        }
        
        int maxsum = 0;
        int p1,p2,p3;
        
        for(int i = k; i < n - k; i++){
            if(dp1[i-1].second + dp2[i+k].second + prefix[i + k] - prefix[i] > maxsum){
                p1 = dp1[i-1].first;
                p2 = i;
                p3 = dp2[i+k].first;
                maxsum = dp1[i-1].second + dp2[i+k].second + prefix[i + k] - prefix[i];
            }
        }
        vector<int> res = {p1,p2,p3};
        return res;
    }
};

//Method - 2
class Solution {
public:
    #define pii pair<int,int>
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> prefix(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        
        vector<pii> dp1(n);
        
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        dp1[k - 1] = {0, sum};
        
        for(int i = k; i < n; i++){
            sum += nums[i];
            sum -= nums[i - k];
            if(dp1[i - 1].second >= sum){
                dp1[i] = dp1[i - 1];
            }
            else{
                dp1[i] = {i - k + 1, sum};
            }
        }
        
        sum = 0;
        
        vector<pii> dp2(n);
        
        for(int i = n - 1; i >= n - k; i--){
            sum += nums[i];
        }
        dp2[n - k] = {n - k, sum};
        
        for(int i = n - k - 1; i >= 0; i--){
            sum += nums[i];
            sum -= nums[i + k];
            if(dp2[i + 1].second > sum){
                dp2[i] = dp2[i + 1];
            }
            else{
                dp2[i] = {i, sum};
            }
        }
        
        int maxSum = 0, p1, p2, p3;
        
        for(int i = k; i < n - k; i++){
             if(dp1[i - 1].second + prefix[i + k] - prefix[i] + dp2[i + k].second > maxSum){
                 maxSum = dp1[i - 1].second + prefix[i + k] - prefix[i] + dp2[i + k].second;
                 p1 = dp1[i - 1].first;
                 p2 = i;
                 p3 = dp2[i + k].first;
             }
        }
        vector<int> res = {p1, p2, p3};
        return res;
    }
};
