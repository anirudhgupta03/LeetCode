//Ref: https://www.youtube.com/watch?v=zqr7jXJ7AQQ
class Solution {
public:
    #define ll long long
    long long minimumDifference(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<ll> prefix(n), suffix(n);
        
        int N = n/3;
        
        priority_queue<ll> pq1;
        
        ll sum = 0;
        
        for(int i = 0; i < N; i++){
            sum += nums[i];
            pq1.push(nums[i]);
        }
        
        prefix[N - 1] = sum;
        
        for(int i = N; i < n; i++){
            sum += nums[i];
            pq1.push(nums[i]);
            sum -= pq1.top();
            pq1.pop();
            prefix[i] = sum;
        }
        
        sum = 0;
        
        priority_queue<ll, vector<ll>, greater<ll>> pq2;
        
        for(int i = n - 1; i >= n - N; i--){
            sum += nums[i];
            pq2.push(nums[i]);
        }
        suffix[n - N] = sum;
        
        for(int i = n - N - 1; i >= 0; i--){
            sum += nums[i];
            pq2.push(nums[i]);
            sum -= pq2.top();
            pq2.pop();
            suffix[i] = sum;
        }
        
        ll minDiff = LLONG_MAX;
        for(int i = N - 1; i < n - N; i++){
            minDiff = min(minDiff, (ll)prefix[i] - suffix[i + 1]);
        }
        return minDiff;
    }
};
