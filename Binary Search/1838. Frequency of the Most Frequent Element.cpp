//Method - 1
class Solution {
public:
    #define ll long long
    bool isPossible(int freq, vector<int> &nums, ll k, vector<ll> &prefix){
        
        ll i = 0, ele = nums[i];
        
        while(i < nums.size() && ele == nums[i]){
            i++;
        }
        if(i >= freq){
            return true;
        }
        while(i < nums.size()){
            ele = nums[i];
            while(i < nums.size() && nums[i] == ele){
                i++;
            }
            if(i - freq >= 0){
                ll op = (ll)freq*nums[i - 1] - (prefix[i] - prefix[i - freq]);
                if(op <= k){
                    return true;
                }
            }
        }
        return false;
    }
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        vector<ll> prefix(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        
        int lo = 1, hi = n, ans;
        
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(isPossible(mid, nums, k, prefix)){
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
