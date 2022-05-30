//Method - 1
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        vector<int> prefix(n,0);
        prefix[0] = arr[0];
        
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }
        
        if(prefix[n - 1] <= target){
            return arr[n - 1];
        }
        
        int lo = 0, hi = 1e5;
        int diff = INT_MAX, ans = INT_MAX;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            int pos = n;
            
            int low = 0, high = n - 1;
            
            while(low <= high){
                
                int tmid = (low + high)/2;
                
                if(arr[tmid] > mid){
                    high = tmid - 1;
                }
                else{
                    pos = tmid;
                    low = tmid + 1;
                }
            }
            
            int d, tsum;
            if(pos != n){
                int lsum = prefix[pos];
                int rsum = mid*(n - pos - 1);
                tsum = lsum + rsum;
            }
            else{
                tsum = n*mid;
            }
            
            d = abs(tsum - target);
            if(d <= diff){
                if(d == diff) ans = min(ans, mid);
                else ans = mid;
                diff = d;
            }
            
            if(tsum > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return ans;
    }
};

//Method - 2
class Solution {
public:
    int mutatedArraySum(int ele, vector<int> &prefix, vector<int> &arr){
        
        int lo = 0, hi = arr.size() - 1;
        int ans = arr.size();
        
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(arr[mid] <= ele){
                lo = mid + 1;
            }
            else{
                ans = mid;
                hi = mid - 1;
            }
        }
        return prefix[ans] + (arr.size() - ans)*ele;
    }
    int findBestValue(vector<int>& arr, int target) {
        
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        vector<int> prefix(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }
        
        if(prefix[n] <= target){
            return arr[n - 1];
        }
        
        int lo = 0, hi = arr[n - 1], minDiff = INT_MAX, ans;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            int sum = mutatedArraySum(mid, prefix, arr);
            
            if(sum < target){
                if(target - sum < minDiff){
                    minDiff = target - sum;
                    ans = mid;
                }
                else if(target - sum == minDiff){
                    ans = min(ans, mid);
                }
                lo = mid + 1;
            }
            else{
                if(sum - target < minDiff){
                    minDiff = sum - target;
                    ans = mid;
                }
                else if(sum - target == minDiff){
                    ans = min(ans, mid);
                }
                hi = mid - 1;
            }
        }
        return ans;
    }
};
