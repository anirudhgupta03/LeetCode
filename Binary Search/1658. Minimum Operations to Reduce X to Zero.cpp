//Ref: https://www.youtube.com/watch?v=7nzwrX4N_A0&t=40s
//Method - 1
//TC - O(N)
//SC - O(N)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        
        sum -= x;
        
        if(sum == 0) return n;
        
        unordered_map<int,int> umap;
        umap[0] = -1;
        
        int maxLenSubarray = -1;
        
        int tsum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            tsum += nums[i];
            
            if(umap.find(tsum - sum) != umap.end()){
                maxLenSubarray = max(maxLenSubarray, i - umap[tsum - sum]);
            }
           
            if(umap.find(tsum) == umap.end()){
                umap[tsum] = i;
            }
        }
        if(maxLenSubarray == -1) return -1;
        return n - maxLenSubarray;
    }
};

//Method - 2
//TC - O(N)
//SC - O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        
        int temp = sum - x, maxlen = -1, tsum = 0;
        
        int lo = 0, hi = 0;
        
        while(hi < nums.size()){
            
            tsum += nums[hi];
            
            if(tsum == temp){
                maxlen = max(maxlen, hi - lo + 1);
            }
            else if(tsum > temp){
                while(lo <= hi && tsum > temp){
                    tsum -= nums[lo];
                    lo++;
                }
                if(tsum == temp){
                    maxlen = max(maxlen, hi - lo + 1);
                }
            }
            hi++;
        }
        if(tsum == temp){
            maxlen = max(maxlen, hi - lo);
        }
        else if(sum > temp){
            while(lo < hi && tsum > temp){
                tsum -= nums[lo];
                lo++;
            }
            if(tsum == temp){
                maxlen = max(maxlen, hi - lo);
            }
        }
        if(maxlen != -1) return nums.size() - maxlen;
        return -1;
    }
};
