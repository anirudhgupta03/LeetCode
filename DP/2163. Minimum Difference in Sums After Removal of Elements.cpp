//Ref: https://www.youtube.com/watch?v=zqr7jXJ7AQQ&ab_channel=CodeWithSunny
class Solution {
public:
    #define ll long long
    long long minimumDifference(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<ll> prefix(n);
        
        ll sum = 0;
        
        priority_queue<ll> pq1;
        
        for(int i = 0; i < n/3; i++){
            sum += nums[i];
            pq1.push(nums[i]);
        }
        
        prefix[n/3 - 1] = sum;
        
        for(int i = n/3; i < n; i++){
            if(nums[i] < pq1.top()){
                sum -= pq1.top();
                sum += nums[i];
                pq1.pop();
                pq1.push(nums[i]);
            }
            prefix[i] = sum;
        }
        
        vector<ll> suffix(n);
        
        sum = 0;
        
        priority_queue<ll, vector<ll>, greater<ll>> pq2;
        
        for(int i = n - 1; i >= (2*n)/3; i--){
            sum += nums[i];
            pq2.push(nums[i]);
        }
        suffix[(2*n)/3] = sum;
        
        for(int i = (2*n)/3 - 1; i >= 0; i--){
            if(nums[i] > pq2.top()){
                sum -= pq2.top();
                sum += nums[i];
                pq2.pop();
                pq2.push(nums[i]);
            }
            suffix[i] = sum;
        }
        
        ll minDiff = LLONG_MAX;
        for(int i = n/3 - 1; i <= (2*n)/3 - 1; i++){
            minDiff = min(minDiff, prefix[i] - suffix[i + 1]);
        }
        return minDiff;
    }
};
