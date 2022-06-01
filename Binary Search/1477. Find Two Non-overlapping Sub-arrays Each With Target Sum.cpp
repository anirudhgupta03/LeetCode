//Method - 1
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

//Method - 2
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int k) {
        
        unordered_map<int,int> umap;
        
        umap[0] = -1;
        
        int n = arr.size(), sum = 0;
        
        vector<int> prefix(n,INT_MAX);
        
        for(int i = 0; i < n; i++){
            
            sum += arr[i];
            
            if(umap.find(sum - k) != umap.end()){
                prefix[i] = i - umap[sum - k];
            }
            
            umap[sum] = i;
        }
        
        umap.clear();
        sum = 0;
        umap[0] = n;
        
        vector<int> suffix(n,INT_MAX);
        
        for(int i = n - 1; i >= 0; i--){
            
            sum += arr[i];
            
            if(umap.find(sum - k) != umap.end()){
                suffix[i] = umap[sum - k] - i;
            }
            umap[sum] = i;
        }
        
        for(int i = 1; i < n; i++){
            prefix[i] = min(prefix[i - 1], prefix[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = min(suffix[i + 1], suffix[i]);
        }
        
        
        int minLen = INT_MAX;
        
        for(int i = 0; i < n - 1; i++){
            if(prefix[i] != INT_MAX && suffix[i + 1] != INT_MAX){
                minLen = min(minLen, prefix[i] + suffix[i + 1]);
            }
        }
        if(minLen == INT_MAX) return -1;
        return minLen;
    }
};
