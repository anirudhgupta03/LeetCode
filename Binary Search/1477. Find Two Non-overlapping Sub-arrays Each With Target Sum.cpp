class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size();
        vector<int> righttoleft(n);
        
        int sum = 0;
        int minlen = INT_MAX;
        
        int lo = n - 1, hi = n - 1;
        
        while(hi >= 0){
            
            sum += arr[hi];
            
            if(sum == target){
                while(hi <= lo && sum == target){
                    minlen = min(minlen, lo - hi + 1);
                    sum -= arr[lo];
                    lo--;
                }
            }
            else if(sum > target){
                while(hi <= lo && sum > target){
                    sum -= arr[lo];
                    lo--;
                }
                if(sum == target){
                    minlen = min(minlen, lo - hi + 1);
                }
            }
            righttoleft[hi] = minlen;
            hi--;
        }
      
        lo = 0, hi = 0;
        minlen = INT_MAX;
        sum = 0;
        
        int ans = INT_MAX;
        
        while(hi < n - 1){
            sum += arr[hi];
            
            if(sum == target){
                while(hi >= lo && sum == target){
                    minlen = min(minlen, hi - lo + 1);
                    sum -= arr[lo];
                    lo++;
                }
            }
            else if(sum > target){
                while(hi >= lo && sum > target){
                    sum -= arr[lo];
                    lo++;
                }
                if(sum == target){
                    minlen = min(minlen, hi - lo + 1);
                }
            }
            if(minlen != INT_MAX && righttoleft[hi + 1] != INT_MAX){
                ans = min(ans, minlen + righttoleft[hi + 1]);
            }
            hi++;
        }
        
        //int ans = INT_MAX;
        //Gives TLE
        // for(int i = 0; i < n - 1; i++){
        //     if(lefttoright[i] != INT_MAX && righttoleft[i + 1] != INT_MAX){
        //         ans = min(ans, lefttoright[i] + righttoleft[i + 1]);
        //     }
        // }
      
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
