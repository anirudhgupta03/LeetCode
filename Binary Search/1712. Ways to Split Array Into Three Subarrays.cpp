class Solution {
public:
    #define ll long long
    int waysToSplit(vector<int>& nums) {
        
        int n = nums.size();
        
        int lo = 0, hi = n - 1;
        
        vector<int> prefix(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        
        int ans = 0;
        int mod = 1e9 + 7;
        
        for(int i = 0; i < n - 2; i++){
            
            int lsum = prefix[i + 1], rsum = prefix[n] - prefix[i + 1];
            
            cout << lsum << " " << rsum << endl;
            
            if(lsum > rsum){
                break;
            }
            else{
                int lo = i + 1, hi = n - 2;
                int start = -1, end = -1;
                
                while(lo <= hi){
                    int mid = (lo + hi)/2;
                    int l = prefix[mid + 1] - prefix[i + 1], r = prefix[n] - prefix[mid + 1];
                    
                    if(l <= r && l >= lsum){
                        start = mid;
                        hi = mid - 1;
                    }
                    else if(l <= r){
                        lo = mid + 1;
                    }
                    else{
                        hi = mid - 1;
                    }
                }
                
                lo = i + 1, hi = n - 2;
                
                while(lo <= hi){
                    int mid = (lo + hi)/2;
                    int l = prefix[mid + 1] - prefix[i + 1], r = prefix[n] - prefix[mid + 1];
                    
                    if(l <= r && l >= lsum){
                        end = mid;
                        lo = mid + 1;
                    }
                    else if(l <= r){
                        lo = mid + 1;
                    }
                    else{
                        hi = mid - 1;
                    }
                }
                if(start != -1 && end != -1) ans = (ans + end - start + 1)%mod;
            }
        }
        return ans;
    }
};
