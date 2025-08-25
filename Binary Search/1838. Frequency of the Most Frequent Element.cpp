//Method - 1
//Binary Search
#define ll long long
class Solution {
public:
    bool isPossible(int freq, vector<int> &nums, vector<ll> &prefix, int k){
        int lo = 0, hi = freq;
        while(hi <= nums.size()){
            ll kSum = (ll)(freq)*nums[hi - 1] - (prefix[hi] - prefix[lo]);
            if(kSum <= k){
                return true;
            }
            lo++;
            hi++;
        }
        return false;
    }
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<ll> prefix(n + 1, 0);

        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        int lo = 1, hi = n, ans = 1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(isPossible(mid, nums, prefix, k)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};

//Method - 2
//Sliding Window
#define ll long long
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();   
        sort(nums.begin(), nums.end());

        int lo = 0, hi = 1, count = 1;
        ll sum = 0;

        while(hi < n){
            while(hi < n && sum <= k){
                sum += (ll)(nums[hi] - nums[hi - 1])*(hi - lo);
                if(sum > k){
                    break;
                }
                hi++;
            }
            count = max(count, hi - lo);
            while(lo <= hi && sum > k){
                sum -= (ll)(nums[hi] - nums[lo]);
                lo++;
            }
            hi++;
        }
        return count;
    }
};

//Method - 3
//Ref: https://www.youtube.com/watch?v=nveGJc_oYAI
class Solution {
public:
    #define ll long long
    bool isPossible(vector<int> &nums, int mid, int k){
        
        ll windowsum = 0, totalsum = 0;
        for(int i = 0; i < mid; i++){
            windowsum += nums[i];
        }
        
        totalsum = (ll)nums[mid - 1]*mid;
        
        if(totalsum - windowsum <= k){
            return 1;
        }
        
        int j = 0;
        
        for(int i = mid; i < nums.size(); i++){
            windowsum -= nums[j];
            windowsum += nums[i];
            totalsum = (ll)nums[i]*mid;
            
            if(totalsum - windowsum <= k){
                return 1;
            }
            j++;
        }
        return 0;
    }
    int maxFrequency(vector<int>& nums, int k) {
        
        int lo = 1, hi = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            if(isPossible(nums, mid, k)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};
